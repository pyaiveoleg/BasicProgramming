package homeworks.homework5.task1

import java.io.InputStream
import java.io.OutputStream

private const val SYMBOLS_TO_SHIFT = 3

class Trie {
    private var size = 0
    private var root = Node()

    class Node {
        var isTerminal = false
        val edges: MutableMap<Char, Node> = mutableMapOf()

        private fun countQuantityOfChildren(): Int {
            var quantity = 0
            for (child in edges.values) {
                if (child.isTerminal) {
                    quantity++
                }
                quantity += child.countQuantityOfChildren()
            }
            return quantity
        }

        fun addElement(element: String, currentIndex: Int, isNewString: Boolean): Boolean {
            var notContainsString = isNewString
            if (currentIndex == element.length) {
                if (!this.isTerminal) {
                    this.isTerminal = true
                }
                return notContainsString
            }
            if (element[currentIndex] !in this.edges.keys) {
                notContainsString = true
            }
            return this.edges.getOrPut(element[currentIndex], { Node() }).addElement(
                element,
                currentIndex + 1, notContainsString
            )
        }

        fun containsElement(element: String, currentIndex: Int): Boolean {
            return when {
                currentIndex == element.length -> true
                element[currentIndex] !in this.edges.keys -> false
                else -> this.edges.getOrPut(element[currentIndex], { Node() }).containsElement(
                    element, currentIndex + 1
                )
            }
        }

        fun howManyStartWithPrefixRecursive(prefix: String, currentIndex: Int): Int {
            var quantity: Int
            when (currentIndex) {
                prefix.length -> {
                    quantity = this.countQuantityOfChildren()
                    if (this.isTerminal) {
                        quantity++
                    }
                }
                else -> {
                    val nextNode = this.edges[prefix[currentIndex]] ?: return 0
                    quantity = nextNode.howManyStartWithPrefixRecursive(prefix, currentIndex + 1)
                }
            }
            return quantity
        }

        fun serializeSubtrie(): String {
            val edges = mutableListOf<String>()
            for (edge in this.edges) {
                edges.add("${edge.key}: ${edge.value.serializeSubtrie()}")
            }
            return "{\"isTerminal\": \"${this.isTerminal}\", \"edges\": $edges}"
        }

        fun areSubtriesEqual(forCompare: Node): Boolean {
            var areEquals = true
            if (forCompare.isTerminal == this.isTerminal && forCompare.edges.size == this.edges.size) {
                for (character in forCompare.edges.keys) {
                    if (!(this.edges[character] ?: return false).areSubtriesEqual(
                            forCompare.edges[character] ?: break
                        )
                    ) {
                        areEquals = false
                    }
                }
            } else {
                areEquals = false
            }
            return areEquals
        }
    }

    fun add(element: String): Boolean {
        val isNewElement = root.addElement(element, 0, false)
        if (isNewElement) {
            size++
        }
        return isNewElement
    }

    fun contains(element: String): Boolean {
        return root.containsElement(element, 0)
    }

    private fun removeElement(element: String, currentIndex: Int, edges: MutableMap<Char, Node>) {
        val currentNode = edges[element[currentIndex]] ?: return
        if (currentIndex == element.length - 1) {
            size--
            if (currentNode.edges.isEmpty()) {
                edges.remove(element[currentIndex])
            } else {
                currentNode.isTerminal = false
            }
        } else {
            removeElement(element, currentIndex + 1, currentNode.edges)
            if (currentNode.edges.isEmpty() && !currentNode.isTerminal) {
                edges.remove(element[currentIndex])
            }
        }
        return
    }

    fun remove(element: String): Boolean {
        return if (!contains(element)) {
            false
        } else {
            size--
            removeElement(element, 0, root.edges)
            true
        }
    }

    fun size(): Int {
        return size
    }

    fun howManyStartWithPrefix(prefix: String): Int {
        return root.howManyStartWithPrefixRecursive(prefix, 0)
    }

    fun equalToTrie(trieForCompare: Trie): Boolean {
        return root.areSubtriesEqual(trieForCompare.root)
    }

    fun serialize(out: OutputStream): String {
        out.write(root.serializeSubtrie().toByteArray())
        out.close()
        return root.serializeSubtrie()
    }

    private fun parseList(currentIndex: Int, jsonList: String, node: Node): Int {
        var index = currentIndex + 1
        var letter = 'a'
        while (index < jsonList.length) {
            when {
                jsonList[index].isLetter() -> {
                    letter = jsonList[index]
                    index++
                }
                jsonList[index] == ' ' || jsonList[index] == ',' || jsonList[index] == ':' -> {
                    index++
                }
                jsonList[index] == '{' -> {
                    val resultOfParse = deserializeSubtrie(index, jsonList)
                    node.edges[letter] = resultOfParse.first
                    index = resultOfParse.second
                }
                jsonList[index] == ']' -> {
                    return index + 1
                }
            }
        }
        return index + 1
    }

    private fun deserializeSubtrie(currentIndex: Int, stringWithTrie: String): Pair<Node, Int> {
        val node = Node()
        var index = currentIndex
        loop@ while (index < stringWithTrie.length) {
            when {
                stringWithTrie[index] == '\"' -> {
                    val endOfParameter = stringWithTrie.slice(
                        index + 1 until stringWithTrie.length
                    ).indexOf('\"') + 1
                    val parameter = stringWithTrie.slice(index + 1 until index + endOfParameter)
                    index += endOfParameter + SYMBOLS_TO_SHIFT
                    if (parameter == "isTerminal") {
                        val endOfValue = stringWithTrie.slice(
                            index + 1 until stringWithTrie.length
                        ).indexOf('\"') + 1
                        val value = stringWithTrie.slice(index + 1 until index + endOfValue).toBoolean()
                        index += endOfValue + 1
                        node.isTerminal = value
                    }
                }
                stringWithTrie[index] == '[' -> {
                    index = parseList(index, stringWithTrie, node)
                }
                stringWithTrie[index] == '}' -> {
                    index++
                    break@loop
                }
                else -> {
                    index++
                }
            }
        }
        return Pair(node, index)
    }

    fun deserialize(input: InputStream) {
        root = deserializeSubtrie(1, input.bufferedReader().readText()).first
    }
}

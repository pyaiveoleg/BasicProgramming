package homeworks.homework5.task1

import java.io.InputStream
import java.io.OutputStream

class Trie {
    private var size = 0
    private var root = Node()

    class Node {
        var isTerminal = false
        val edges: MutableMap<Char, Node> = mutableMapOf()
    }

    private fun addElement(element: String, currentIndex: Int, currentNode: Node, isNewString: Boolean): Boolean {
        var notContainsString = isNewString
        if (currentIndex == element.length) {
            if (!currentNode.isTerminal) {
                currentNode.isTerminal = true
                size++
            }
            return notContainsString
        }
        if (element[currentIndex] !in currentNode.edges.keys) {
            notContainsString = true
        }
        return addElement(element, currentIndex + 1, currentNode.edges.getOrPut(element[currentIndex], { Node() }), notContainsString)
    }

    fun add(element: String): Boolean {
        return addElement(element, 0, root, false)
    }

    private fun containsElement(element: String, currentIndex: Int, currentNode: Node): Boolean {
        return when {
            currentIndex == element.length -> true
            element[currentIndex] !in currentNode.edges.keys -> false
            else -> containsElement(element, currentIndex + 1, currentNode.edges.getOrPut(element[currentIndex], { Node() }))
        }
    }

    fun contains(element: String): Boolean {
        return containsElement(element, 0, root)
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

    private fun howManyStartWithPrefixRecursive(prefix: String, currentIndex: Int, currentNode: Node): Int {
        return when {
            currentIndex == prefix.length -> currentNode.edges.keys.size
            prefix[currentIndex] !in currentNode.edges.keys -> 0
            else -> howManyStartWithPrefixRecursive(prefix, currentIndex + 1, currentNode)
        }
    }

    fun howManyStartWithPrefix(prefix: String): Int {
        return howManyStartWithPrefixRecursive(prefix,0, root)
    }

    private fun areSubtriesEqual(firstRoot: Node, secondRoot: Node): Boolean {
        var areEquals = true
        if (firstRoot.isTerminal == secondRoot.isTerminal && firstRoot.edges.size == secondRoot.edges.size) {
            for (character in firstRoot.edges.keys) {
                if (!areSubtriesEqual(firstRoot.edges[character] ?: break, secondRoot.edges[character] ?: return false)) {
                    areEquals = false
                }
            }
        } else {
            areEquals = false
            println(firstRoot.isTerminal)
            println(secondRoot.isTerminal)
            println(firstRoot.edges.size)
            println(secondRoot.edges)
        }
        return areEquals
    }

    fun equalToTrie(trieForCompare: Trie): Boolean {
        return areSubtriesEqual(root, trieForCompare.root)
    }

    private fun serializeSubtrie(root: Node): String {
        val edges = mutableListOf<String>()
        for (edge in root.edges) {
            edges.add("${edge.key}: ${serializeSubtrie(edge.value)}")
        }
        return "{\"isTerminal\": \"${root.isTerminal}\", \"edges\": $edges}"
    }

    fun serialize(out: OutputStream): String {
        out.write(serializeSubtrie(root).toByteArray())
        out.close()
        return serializeSubtrie(root)
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
                jsonList[index] == ' ' || jsonList[index] == ',' ||  jsonList[index] == ':' -> {
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

    private fun deserializeSubtrie(currentIndex: Int, stringWithTrie: String): Pair <Node, Int> {
        val node = Node()
        var index = currentIndex
        loop@ while (index < stringWithTrie.length) {
            when {
                stringWithTrie[index] == '\"' -> {
                    val endOfParameter = stringWithTrie.slice(index + 1 until stringWithTrie.length).indexOf('\"')
                    val parameter = stringWithTrie.slice(index + 1 .. index + endOfParameter)
                    index += endOfParameter + 4
                    if (parameter == "isTerminal") {
                        val endOfValue = stringWithTrie.slice(index + 1 until stringWithTrie.length).indexOf('\"')
                        val value = stringWithTrie.slice(index + 1.. index + endOfValue).toBoolean()
                        index += endOfValue + 4
                        node.isTerminal = value
                    }
                }
                stringWithTrie[index] == '['-> {
                    index = parseList(index, stringWithTrie, node)
                }
                stringWithTrie[index] == ' ' || stringWithTrie[index] == '{' -> {
                    index++
                }
                stringWithTrie[index] == '}' -> {
                    index++
                    break@loop
                }
            }
        }
        return Pair(node, index)
    }

    fun deserialize(input: InputStream) {
        root = deserializeSubtrie(1, input.bufferedReader().readText()).first
    }
}

package homeworks.homework5.task1

import java.io.IOException
import java.io.InputStream
import java.io.OutputStream
import java.io.Serializable

class Trie(private val root: Node) : Serializable {
    private var quantityOfWords = 0

    fun add(element: String): Boolean {
        val isNewElement = root.addElement(element, 0)
        if (isNewElement) {
            quantityOfWords++
        }
        return isNewElement
    }

    fun contains(element: String): Boolean {
        return root.containsElement(element, 0)
    }

    fun remove(element: String): Boolean {
        if (!contains(element)) {
            return false
        }
        quantityOfWords--
        root.removeElement(element, 0)
        return true
    }

    fun getQuantityOfWords(): Int {
        return quantityOfWords
    }

    fun howManyStartWithPrefix(prefix: String): Int {
        return root.howManyStartWithPrefixRecursive(prefix, 0)
    }

    override fun equals(other: Any?): Boolean {
        if (other !is Trie) {
            return false
        }
        return root.equal(other.root)
    }

    @Throws(IOException::class)
    fun writeObject(out: OutputStream) {
        out.write(root.serializeSubtrie().toByteArray())
        out.close()
        return
    }

    companion object Deserialize {
        private const val symbolsToShift = 3

        @Throws(IOException::class, ClassNotFoundException::class)
        fun readObject(input: InputStream): Trie {
            return Trie(deserializeSubtrie(1, input.bufferedReader().readText()).node)
        }

        data class PointInStringWithTree(
            val node: Node,
            val index: Int
        )

        private fun deserializeSubtrie(currentIndex: Int, stringWithTrie: String): PointInStringWithTree {
            val node = Node()
            var index = currentIndex
            loop@ while (index < stringWithTrie.length) {
                when {
                    stringWithTrie[index] == '\"' -> {
                        val endOfParameter = stringWithTrie.slice(
                            index + 1 until stringWithTrie.length
                        ).indexOf('\"') + 1
                        val parameter = stringWithTrie.slice(index + 1 until index + endOfParameter)
                        index += endOfParameter + symbolsToShift
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
            return PointInStringWithTree(node, index)
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
                        node.edges[letter] = resultOfParse.node
                        index = resultOfParse.index
                    }
                    jsonList[index] == ']' -> {
                        return index + 1
                    }
                }
            }
            return index + 1
        }
    }
}

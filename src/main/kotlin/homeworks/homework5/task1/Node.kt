package homeworks.homework5.task1

class Node {
    var isTerminal = false
    var startWithPrefix = 0
    val edges: MutableMap<Char, Node> = mutableMapOf()

    fun addElement(element: String, currentIndex: Int): Boolean {
        if (currentIndex == element.length) {
            val isNewString = !this.isTerminal
            if (isNewString) {
                this.isTerminal = true
            }
            return isNewString
        }
        this.startWithPrefix++
        return edges.getOrPut(element[currentIndex], { Node() }).addElement(element, currentIndex + 1)
    }

    fun containsElement(element: String, currentIndex: Int): Boolean {
        return when {
            (currentIndex == element.length) && isTerminal -> true
            element[currentIndex] !in this.edges.keys -> false
            else -> edges.getOrPut(element[currentIndex], { Node() }).containsElement(
                element, currentIndex + 1
            )
        }
    }

    fun howManyStartWithPrefixRecursive(prefix: String, currentIndex: Int): Int {
        var quantity: Int
        when (currentIndex) {
            prefix.length -> {
                quantity = this.startWithPrefix
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

    fun equal(forCompare: Node): Boolean {
        var areEquals = true
        if (forCompare.isTerminal == this.isTerminal && forCompare.edges.size == this.edges.size) {
            for (character in forCompare.edges.keys) {
                if (!(this.edges[character] ?: return false).equal(
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

    fun removeElement(element: String, currentIndex: Int) {
        val currentNode = edges[element[currentIndex]] ?: return
        if (currentIndex == element.length - 1) {
            if (currentNode.edges.isEmpty()) {
                edges.remove(element[currentIndex])
            } else {
                currentNode.isTerminal = false
            }
        } else {
            currentNode.removeElement(element, currentIndex + 1)
            if (currentNode.edges.isEmpty() && !currentNode.isTerminal) {
                edges.remove(element[currentIndex])
            }
        }
        return
    }
}

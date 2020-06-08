package homeworks.homework3.task1

class Entry<K, V>(override var key: K, override var value: V) : Map.Entry<K, V>

class AVLTree<K : Comparable<K>, V> : Map<K, V> {
    private var root: Node<K, V>? = null

    override val entries: Set<Map.Entry<K, V>>
        get() {
            val entries = mutableSetOf<Map.Entry<K, V>>()
            val queue = mutableListOf<Node<K, V>?>()
            queue.add(root)
            while (queue.isNotEmpty()) {
                val currentNode = queue.removeAt(queue.size - 1)
                currentNode?.let {
                    entries.add(Entry(currentNode.key, currentNode.value))
                    queue.add(it.leftChild)
                    queue.add(it.rightChild)
                }
            }
            return entries
        }

    override val keys: Set<K>
        get() {
            val keys = mutableSetOf<K>()
            for (entry in entries) {
                keys.add(entry.key)
            }
            return keys
        }

    override val values: Collection<V>
        get() {
            val values = mutableListOf<V>()
            for (entry in entries) {
                values.add(entry.value)
            }
            return values
        }

    override var size = 0
        private set

    class OperationsWithNodes<K : Comparable<K>, V> {
        fun delete(keyForDelete: K, currentNode: Node<K, V>): Node<K, V>? {
            if (keyForDelete < currentNode.key) {
                val leftChild = currentNode.leftChild
                if (leftChild != null) {
                    currentNode.leftChild = delete(keyForDelete, leftChild)
                }
            } else if (keyForDelete > currentNode.key) {
                val rightChild = currentNode.rightChild
                if (rightChild != null) {
                    currentNode.leftChild = delete(keyForDelete, rightChild)
                }
            } else {
                val leftChild = currentNode.leftChild
                val rightChild = currentNode.rightChild
                val node: Node<K, V>?

                when {
                    rightChild == null -> {
                        node = currentNode.leftChild
                    }
                    leftChild == null -> {
                        node = currentNode.rightChild
                    }
                    else -> {
                        val nodeWithMaxKeyInSubtree = leftChild.findNodeWithMaxKeyInSubtree()
                        nodeWithMaxKeyInSubtree.rightChild = leftChild.removeNodeWithMaxKeyInSubtree()
                        nodeWithMaxKeyInSubtree.leftChild = leftChild
                        node = nodeWithMaxKeyInSubtree.balance()
                    }
                }
                return node
            }
            return currentNode.balance()
        }

        fun subtreeEquals(firstNode: Node<K, V>?, secondNode: Node<K, V>?): Boolean {
            if ((firstNode == null) && (secondNode == null)) {
                return true
            }
            if ((firstNode == null) || (secondNode == null)) {
                return false
            }
            if (firstNode.key != secondNode.key || firstNode.value != secondNode.value) {
                return false
            }
            return subtreeEquals(firstNode.leftChild, secondNode.leftChild) &&
                    subtreeEquals(firstNode.rightChild, secondNode.rightChild)
        }

        fun insert(keyForInsert: K, valueForInsert: V, currentNode: Node<K, V>): Node<K, V>? {
            if (keyForInsert < currentNode.key) {
                val leftChild = currentNode.leftChild
                if (leftChild == null) {
                    currentNode.leftChild = Node(keyForInsert, valueForInsert)
                } else {
                    currentNode.leftChild = insert(keyForInsert, valueForInsert, leftChild)
                }
            } else if (keyForInsert > currentNode.key) {
                val rightChild = currentNode.rightChild
                if (rightChild == null) {
                    currentNode.rightChild = Node(keyForInsert, valueForInsert)
                } else {
                    currentNode.rightChild = insert(keyForInsert, valueForInsert, rightChild)
                }
            } else {
                currentNode.value = valueForInsert
            }
            return currentNode.balance()
        }
    }

    fun addElement(keyForInsert: K, valueForInsert: V) {
        val root = this.root
        if (root == null) {
            this.root = Node(keyForInsert, valueForInsert)
        } else {
            this.root = OperationsWithNodes<K, V>().insert(keyForInsert, valueForInsert, root)
        }
        size++
    }

    private fun find(key: K, currentNode: Node<K, V>?): V? {
        if (currentNode == null) {
            return null
        }
        return when {
            key < currentNode.key -> find(key, currentNode.leftChild)
            key > currentNode.key -> find(key, currentNode.rightChild)
            else -> currentNode.value
        }
    }

    fun deleteElement(key: K) {
        val root = this.root
        if (root != null) {
            this.root = OperationsWithNodes<K, V>().delete(key, root)
        }
        size--
    }

    fun equalsToTree(treeForCompare: AVLTree<K, V>): Boolean {
        return OperationsWithNodes<K, V>().subtreeEquals(this.root, treeForCompare.root)
    }

    override fun toString(): String {
        return "${root?.toString()}"
    }

    override fun containsKey(key: K) = get(key) != null
    override fun containsValue(value: V) = values.contains(value)

    override fun get(key: K): V? {
        val root = this.root
        return root?.let { find(key, it) }
    }

    override fun isEmpty() = size == 0
}

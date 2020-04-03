package homeworks.homework3.task1

import java.lang.Integer.max

class AVLTree<K : Comparable<K>, V> {
    private var root: Node<K, V>? = null
    private var size = 0

    class Node<K, V>(var key: K, val value: V) where K : Comparable<K> {
        private var height = 0
        var leftChild: Node<K, V>? = null
        var rightChild: Node<K, V>? = null
        private val balanceFactorToFix = 2

        private fun getBalanceFactor(): Int {
            return (rightChild?.height ?: -1) - (leftChild?.height ?: -1)
        }

        private fun updateHeight() {
            height = max(rightChild?.height ?: -1, leftChild?.height ?: -1) + 1
        }

        private fun rotateRight(): Node<K, V>? {
            val pivot = leftChild
            leftChild = pivot?.rightChild
            pivot?.rightChild = this
            this.updateHeight()
            pivot?.updateHeight()
            return pivot
        }

        private fun rotateLeft(): Node<K, V>? {
            val pivot = rightChild
            rightChild = pivot?.leftChild
            pivot?.leftChild = this
            this.updateHeight()
            pivot?.updateHeight()
            return pivot
        }

        fun balance(): Node<K, V>? {
            updateHeight()
            var newPivot: Node<K, V>? = this
            if (getBalanceFactor() == balanceFactorToFix) {
                if (rightChild?.getBalanceFactor() ?: -1 < 0) {
                    rightChild = rightChild?.rotateRight()
                }
                newPivot = rotateLeft()
            } else if (getBalanceFactor() == -balanceFactorToFix) {
                if (leftChild?.getBalanceFactor() ?: -1 > 0) {
                    leftChild = leftChild?.rotateLeft()
                }
                newPivot = rotateRight()
            }
            return newPivot
        }

        fun findNodeWithMaxKeyInSubtree(): Node<K, V> {
            return rightChild?.findNodeWithMaxKeyInSubtree() ?: this
        }

        fun removeNodeWithMaxKeyInSubtree(): Node<K, V>? {
            rightChild = rightChild?.removeNodeWithMaxKeyInSubtree() ?: return leftChild
            return balance()
        }

        fun printSubtree(): String {
            return "([key: $key, value: $value] ${leftChild?.printSubtree()} ${rightChild?.printSubtree()})"
        }
    }

    private fun delete(keyForDelete: K, currentNode: Node<K, V>): Node<K, V>? {
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

    private fun insert(keyForInsert: K, valueForInsert: V, currentNode: Node<K, V>): Node<K, V>? {
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
        }
        return currentNode.balance()
    }

    fun addElement(keyForInsert: K, valueForInsert: V) {
        val root = this.root
        if (root == null) {
            this.root = Node(keyForInsert, valueForInsert)
        } else {
            this.root = insert(keyForInsert, valueForInsert, root)
        }
        size++
    }

    private fun find(key: K, currentNode: Node<K, V>): V? {
        var value: V? = currentNode.value
        if (key < currentNode.key) {
            val leftChild = currentNode.leftChild
            if (leftChild == null) {
                value = null
            } else {
                value = find(key, leftChild)
            }
        }
        if (key > currentNode.key) {
            val rightChild = currentNode.rightChild
            if (rightChild == null) {
                value = null
            } else {
                value = find(key, rightChild)
            }
        }
        return value
    }

    fun containsElement(key: K): Boolean {
        val root = this.root
        return if (root == null) {
            false
        } else {
            find(key, root) != null
        }
    }

    fun getValue(key: K): V? {
        val root = this.root
        return if (root == null) {
            null
        } else {
            find(key, root)
        }
    }

    fun deleteElement(key: K) {
        val root = this.root
        if (root != null) {
            this.root = delete(key, root)
        }
        size--
    }

    private fun subtreeEquals(firstNode: Node<K, V>?, secondNode: Node<K, V>?): Boolean {
        if (firstNode == null) {
            if (secondNode == null) {
                return true
            }
            return false
        }
        if (secondNode == null) {
            return false
        }
        if (firstNode.key != secondNode.key || firstNode.value != secondNode.value) {
            return false
        }
        if (!subtreeEquals(firstNode.leftChild, secondNode.leftChild) ||
            !subtreeEquals(firstNode.rightChild, secondNode.rightChild)
        ) {
            return false
        }
        return true
    }

    fun equalsToTree(treeForCompare: AVLTree<K, V>): Boolean {
        return subtreeEquals(this.root, treeForCompare.root)
    }

    fun printTree() {
        print("This is a tree: ${root?.printSubtree()}\n")
    }
}

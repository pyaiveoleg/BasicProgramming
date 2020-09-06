package homeworks.homework3.task1

class Node<K, V>(var key: K, var value: V) where K : Comparable<K> {
    private var height = 0
    var leftChild: Node<K, V>? = null
    var rightChild: Node<K, V>? = null
    private val balanceFactorToFix = 2

    private fun getBalanceFactor(): Int {
        return (rightChild?.height ?: -1) - (leftChild?.height ?: -1)
    }

    private fun updateHeight() {
        height = Integer.max(rightChild?.height ?: -1, leftChild?.height ?: -1) + 1
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
        if (rightChild == null) {
            return leftChild
        }
        rightChild = rightChild?.removeNodeWithMaxKeyInSubtree()
        return balance()
    }

    override fun toString(): String {
        return "([key: $key, value: $value] ${leftChild?.toString()} ${rightChild?.toString()})"
    }

    fun equalTo(nodeForCompare: Node<K, V>?): Boolean {
        return this.toString() == nodeForCompare.toString()
    }
}

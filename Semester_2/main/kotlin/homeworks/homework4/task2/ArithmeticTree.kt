package homeworks.homework4.task2

import java.lang.IllegalArgumentException

class ArithmeticTree(private val stringWithTree: String) {
    private val root: Node

    init {
        root = importSubtree(0, stringWithTree.length - 1)
    }

    companion object Config {
        private const val shiftForOperator = 3
    }

    private fun splitString(stringWithSubtree: String): Int {
        var quantityOfNonClosedBrackets = 0

        if (stringWithSubtree[0].isDigit()) {
            return stringWithSubtree.indexOf(' ')
        }

        for (i in stringWithSubtree.indices) {
            if (stringWithSubtree[i] == '(') {
                quantityOfNonClosedBrackets++
            }
            if (stringWithSubtree[i] == ')') {
                quantityOfNonClosedBrackets--
            }
            if (quantityOfNonClosedBrackets == 0) {
                return i + 1
            }
        }
        throw IllegalArgumentException("Invalid input")
    }

    private fun importSubtree(start: Int, end: Int): Node {
        if (stringWithTree[start] != '(') {
            return NodeOperand(stringWithTree.slice(start..end).toDouble())
        }
        val stringForParse = stringWithTree.slice(start + shiftForOperator until end)
        val gapBetweenLeftAndRightNotation = splitString(stringForParse) + shiftForOperator + start
        val leftChild = importSubtree(start + shiftForOperator, gapBetweenLeftAndRightNotation - 1)
        val rightChild = importSubtree(gapBetweenLeftAndRightNotation + 1, end - 1)
        return NodeOperator(stringWithTree[start + 1], leftChild, rightChild)
    }

    fun getValue(): Double {
        return root.calculateValue()
    }

    override fun toString(): String {
        return root.toString()
    }
}

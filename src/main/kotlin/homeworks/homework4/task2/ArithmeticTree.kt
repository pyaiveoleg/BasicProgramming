package homeworks.homework4.task2

class ArithmeticTree(private val root: Node) {
    companion object ImportTree {
        private const val shiftForOperator = 3

        fun importTree(stringWithTree: String): ArithmeticTree {
            return ArithmeticTree(importSubtree(0, stringWithTree.length - 1, stringWithTree))
        }

        private fun splitString(stringWithSubtree: String): Int {
            var quantityOfNonClosedBrackets = 0
            var valueToReturn = 0
            if (stringWithSubtree[0].isDigit()) {
                valueToReturn = stringWithSubtree.indexOf(' ')
            } else {
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
            }
            return valueToReturn
        }

        private fun importSubtree(start: Int, end: Int, stringWithTree: String): Node {
            if (stringWithTree[start] != '(') {
                return NodeOperand(stringWithTree.slice(start..end).toDouble())
            }
            val stringForParse = stringWithTree.slice(start + shiftForOperator until end)
            val gapBetweenLeftAndRightNotation = splitString(stringForParse) + shiftForOperator + start
            val leftChild = importSubtree(start + shiftForOperator, gapBetweenLeftAndRightNotation - 1, stringWithTree)
            val rightChild = importSubtree(gapBetweenLeftAndRightNotation + 1, end - 1, stringWithTree)
            return NodeOperator(stringWithTree[start + 1], leftChild, rightChild)
        }
    }

    fun getValue(): Double {
        return root.calculateValue()
    }

    override fun toString(): String {
        return root.toString()
    }
}

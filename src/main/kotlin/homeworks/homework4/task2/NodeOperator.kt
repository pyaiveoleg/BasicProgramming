package homeworks.homework4.task2

class NodeOperator(
    private val operator: Char,
    private val leftChild: Node,
    private val rightChild: Node
) : Node {
    override val value = calculateValue()

    override fun calculateValue(): Double {
        leftChild.calculateValue()
        rightChild.calculateValue()
        val leftValue = leftChild.value
        val rightValue = rightChild.value

        if (operator in arrayListOf('+', '-', '*', '/')) {
            print(operator)
            return when (operator) {
                '+' -> leftValue + rightValue
                '-' -> leftValue - rightValue
                '*' -> leftValue * rightValue
                '/' -> leftValue / rightValue
                else -> 0.0
            }
        }
        throw IllegalArgumentException("Illegal operator")
    }

    override fun toString(): String {
        return "([operator: $operator, value: $value] $leftChild $rightChild)"
    }
}

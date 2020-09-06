package homeworks.homework4.task2

class NodeOperand(override val value: Double) : Node {
    override fun calculateValue(): Double {
        return value
    }

    override fun toString(): String {
        return value.toString()
    }
}

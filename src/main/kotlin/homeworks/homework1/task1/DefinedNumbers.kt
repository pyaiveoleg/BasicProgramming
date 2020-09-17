package homeworks.homework1.task1

class DefinedNumbers(private val numbers: DoubleArray) : RandomProbabilityGenerator {
    private var index: Int = -1
    override fun generateProbability(): Double {
        index += 1
        if (index >= numbers.size) {
            index = 0
        }
        return numbers[index]
    }
}

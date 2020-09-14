package homeworks.homework1.task1

class DefinedNumbers(private val numbers: DoubleArray) : RandomGenerator {
    private var index: Int = -1
    override fun generateRandomDouble(): Double {
        index += 1
        if (index >= numbers.size) {
            index = 0
        }
        return numbers[index]
    }
}

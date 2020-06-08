package homeworks.homework4.task1

class SimpleHash : HashFunction {
    override fun calculateHash(string: String): Int {
        return string.map { it.toInt() }.sum()
    }
}

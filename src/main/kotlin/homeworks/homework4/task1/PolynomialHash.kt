package homeworks.homework4.task1

import kotlin.math.pow

class PolynomialHash : HashFunction {
    companion object Config {
        private const val BIG_PRIMARY_NUMBER = 1000000009.0
    }
    override fun calculateHash(string: String): Int {
        return string.mapIndexed { i, it -> (it.toInt() * BIG_PRIMARY_NUMBER.pow(i)).toInt() }.sum()
    }
}

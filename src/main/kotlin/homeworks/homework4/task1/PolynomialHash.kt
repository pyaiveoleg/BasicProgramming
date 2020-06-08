package homeworks.homework4.task1

import kotlin.math.pow

class PolynomialHash : HashFunction {
    companion object Config {
        private const val BIG_PRIMARY_NUMBER = 1000000009.0
    }
    override fun calculateHash(string: String): Int {
        var hash = 0
        var index = 0
        for (character in string) {
            hash += (character.toInt() * BIG_PRIMARY_NUMBER.pow(index)).toInt()
            index++
        }
        return hash
    }
}

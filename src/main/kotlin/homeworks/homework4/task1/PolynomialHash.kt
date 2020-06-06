package homeworks.homework4.task1

import kotlin.math.pow

private const val BIG_PRIMARY_NUMBER = 1000000009.0

class PolynomialHash : HashFunction {
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

package homeworks.homework4.task1

import org.junit.jupiter.api.Assertions.assertEquals
import org.junit.jupiter.api.Assertions.assertFalse
import org.junit.jupiter.api.Test
import kotlin.math.pow

private const val BIG_PRIMARY_NUMBER = 1000000009.0

internal class HashTableTest {
    private val sizeOfHash = 1000
    private val maxLoadFactor = 0.9

    @Test
    fun search_containsConsistOfOneElement() {
        val table = HashTable(sizeOfHash, maxLoadFactor) { string: String -> calculatePolynomialHash(string) }
        table.addToTable("test")
        assert(table.search("test"))
    }

    @Test
    fun search_notContainsConsistOfOneElement() {
        val table = HashTable(sizeOfHash, maxLoadFactor) { string: String -> calculatePolynomialHash(string) }
        table.addToTable("test")
        assertFalse(table.search("not_test"))
    }

    @Test
    fun search_notContainsConsistOfSeveralElements() {
        val table = HashTable(sizeOfHash, maxLoadFactor) { string: String -> calculatePolynomialHash(string) }
        table.addToTable("test")
        table.addToTable("test2")
        table.addToTable("test3")
        assertFalse(table.search("not_test"))
    }

    @Test
    fun search_containsConsistOfSeveralElements() {
        val table = HashTable(sizeOfHash, maxLoadFactor) { string: String -> calculatePolynomialHash(string) }
        table.addToTable("test")
        table.addToTable("test2")
        table.addToTable("test3")
        assert(table.search("test2"))
    }

    @Test
    fun expand_sizeOfHashIsThree() {
        val smallSizeOfHash = 3
        val table = HashTable(smallSizeOfHash, maxLoadFactor) { string: String -> calculatePolynomialHash(string) }
        table.addToTable("test")
        table.addToTable("test2")
        table.addToTable("test3")
        table.addToTable("test4")
        assert(table.search("test2"))
    }

    @Test
    fun expand_bigSizeOfHash() {
        val table = HashTable(sizeOfHash, maxLoadFactor) { string: String -> calculatePolynomialHash(string) }
        for (i in 1 until 2000) {
            table.addToTable("test$i")
        }
        assert(table.search("test1000"))
    }

    @Test
    fun expand_bigSizeOfHashNotContains() {
        val table = HashTable(sizeOfHash, maxLoadFactor) { string: String -> calculatePolynomialHash(string) }
        for (i in 1 until 2000) {
            table.addToTable("test$i")
        }
        assertFalse(table.search("abs"))
    }

    @Test
    fun changeHash_polynomialToSimple() {
        val table = HashTable(sizeOfHash, maxLoadFactor) { string: String -> calculatePolynomialHash(string) }
        table.addToTable("test")
        table.addToTable("test2")
        table.addToTable("test3")
        table.changeHash { string: String -> calculateSimpleHash(string) }
        assert(table.search("test2"))
    }

    @Test
    fun changeHash_simpleToPolynomial() {
        val table = HashTable(sizeOfHash, maxLoadFactor) { string: String -> calculatePolynomialHash(string) }
        table.addToTable("test")
        table.addToTable("test2")
        table.addToTable("test3")
        table.changeHash { string: String -> calculateSimpleHash(string) }
        assert(table.search("test2"))
    }

    private fun calculateSimpleHash(string: String): Int {
        var hash = 0
        for (character in string) {
            hash += character.toInt()
        }
        return hash
    }

    private fun calculatePolynomialHash(string: String): Int {
        var hash = 0
        var index = 0
        for (character in string) {
            hash += (character.toInt() * BIG_PRIMARY_NUMBER.pow(index)).toInt()
            index++
        }
        return hash
    }
}

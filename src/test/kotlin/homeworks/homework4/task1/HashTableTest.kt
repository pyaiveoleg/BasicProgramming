package homeworks.homework4.task1

import org.junit.jupiter.api.Assertions.assertEquals
import org.junit.jupiter.api.Test
import kotlin.math.pow

internal class HashTableTest {
    private val sizeOfHash = 1000
    private val maxLoadFactor = 0.9

    @Test
    fun search_containsConsistOfOneElement() {
        val table = HashTable(sizeOfHash, maxLoadFactor) { string: String -> calculatePolynomialHash(string) }
        table.addToTable("test")
        assertEquals(true, table.search("test"))
    }

    @Test
    fun search_notContainsConsistOfOneElement() {
        val table = HashTable(sizeOfHash, maxLoadFactor) { string: String -> calculatePolynomialHash(string) }
        table.addToTable("test")
        assertEquals(false, table.search("not_test"))
    }

    @Test
    fun search_notContainsConsistOfSeveralElements() {
        val table = HashTable(sizeOfHash, maxLoadFactor) { string: String -> calculatePolynomialHash(string) }
        table.addToTable("test")
        table.addToTable("test2")
        table.addToTable("test3")
        assertEquals(false, table.search("not_test"))
    }

    @Test
    fun search_containsConsistOfSeveralElements() {
        val table = HashTable(sizeOfHash, maxLoadFactor) { string: String -> calculatePolynomialHash(string) }
        table.addToTable("test")
        table.addToTable("test2")
        table.addToTable("test3")
        assertEquals(true, table.search("test2"))
    }

    @Test
    fun expand_sizeOfHashIsThree() {
        val smallSizeOfHash = 3
        val table = HashTable(smallSizeOfHash, maxLoadFactor) { string: String -> calculatePolynomialHash(string) }
        table.addToTable("test")
        table.addToTable("test2")
        table.addToTable("test3")
        table.addToTable("test4")
        assertEquals(true, table.search("test2"))
    }

    @Test
    fun expand_bigSizeOfHash() {
        val table = HashTable(sizeOfHash, maxLoadFactor) { string: String -> calculatePolynomialHash(string) }
        for (i in 1 until 2000) {
            table.addToTable("test$i")
        }
        assertEquals(true, table.search("test1000"))
    }

    @Test
    fun expand_bigSizeOfHashNotContains() {
        val table = HashTable(sizeOfHash, maxLoadFactor) { string: String -> calculatePolynomialHash(string) }
        for (i in 1 until 2000) {
            table.addToTable("test$i")
        }
        assertEquals(false, table.search("abs"))
    }

    @Test
    fun changeHash_polynomialToSimple() {
        val table = HashTable(sizeOfHash, maxLoadFactor) { string: String -> calculatePolynomialHash(string) }
        table.addToTable("test")
        table.addToTable("test2")
        table.addToTable("test3")
        table.changeHash { string: String -> calculateSimpleHash(string) }
        assertEquals(true, table.search("test2"))
    }

    @Test
    fun changeHash_simpleToPolynomial() {
        val table = HashTable(sizeOfHash, maxLoadFactor) { string: String -> calculatePolynomialHash(string) }
        table.addToTable("test")
        table.addToTable("test2")
        table.addToTable("test3")
        table.changeHash { string: String -> calculateSimpleHash(string) }
        assertEquals(true, table.search("test2"))
    }

    private fun calculateSimpleHash(string: String): Int {
        var hash = 0
        for (character in string) {
            hash += character.toInt()
        }
        return hash
    }

    private fun calculatePolynomialHash(string: String): Int {
        val bigPrimaryNumber = (10.0.pow(9.0) + 9)
        var hash = 0
        var index = 0
        for (character in string) {
            hash += (character.toInt() * bigPrimaryNumber.pow(index)).toInt()
            index++
        }
        return hash
    }
}

package homeworks.homework4.task1

import org.junit.jupiter.api.Assertions.assertFalse
import org.junit.jupiter.api.Test
import org.junit.jupiter.params.ParameterizedTest
import org.junit.jupiter.params.provider.ValueSource

internal class HashTableTest {
    private val sizeOfHash = TableClient.SIZE_OF_HASH
    private val maxLoadFactor = TableClient.MAX_LOAD_FACTOR

    @Test
    fun search_containsConsistOfOneElement() {
        val table = HashTable(sizeOfHash, maxLoadFactor, PolynomialHash())
        table.addToTable("test")
        assert(table.search("test"))
    }

    @Test
    fun search_notContainsConsistOfOneElement() {
        val table = HashTable(sizeOfHash, maxLoadFactor, PolynomialHash())
        table.addToTable("test")
        assertFalse(table.search("not_test"))
    }

    @Test
    fun search_notContainsConsistOfSeveralElements() {
        val table = HashTable(sizeOfHash, maxLoadFactor, PolynomialHash())
        table.addToTable("test")
        table.addToTable("test2")
        table.addToTable("test3")
        assertFalse(table.search("not_test"))
    }

    @ParameterizedTest
    @ValueSource(ints = [1, 2, 3])
    fun search_containsConsistOfSeveralElements(number: Int) {
        val table = HashTable(sizeOfHash, maxLoadFactor, PolynomialHash())
        table.addToTable("test1")
        table.addToTable("test2")
        table.addToTable("test3")
        assert(table.search("test$number"))
    }

    @ParameterizedTest
    @ValueSource(ints = [1, 2, 3, 4])
    fun expand_sizeOfHashIsThree(number: Int) {
        val smallSizeOfHash = 3
        val table = HashTable(smallSizeOfHash, maxLoadFactor, PolynomialHash())
        table.addToTable("test1")
        table.addToTable("test2")
        table.addToTable("test3")
        table.addToTable("test4")
        assert(table.search("test$number"))
    }

    @Test  // kotlin doesn't allow to pass list from range there
    fun expand_bigSizeOfHash() {
        val table = HashTable(sizeOfHash, maxLoadFactor, PolynomialHash())
        for (i in 1 until 2000) {
            table.addToTable("test$i")
        }
        assert(table.search("test1000"))
    }

    @Test
    fun expand_bigSizeOfHashNotContains() {
        val table = HashTable(sizeOfHash, maxLoadFactor, PolynomialHash())
        for (i in 1 until 2000) {
            table.addToTable("test$i")
        }
        assertFalse(table.search("est1"))
    }

    @ParameterizedTest
    @ValueSource(ints = [1, 2, 3])
    fun changeHash_polynomialToSimple(number: Int) {
        val table = HashTable(sizeOfHash, maxLoadFactor, PolynomialHash())
        table.addToTable("test1")
        table.addToTable("test2")
        table.addToTable("test3")
        table.changeHash(SimpleHash())
        assert(table.search("test$number"))
    }

    @ParameterizedTest
    @ValueSource(ints = [1, 2, 3])
    fun changeHash_simpleToPolynomial(number: Int) {
        val table = HashTable(sizeOfHash, maxLoadFactor, PolynomialHash())
        table.addToTable("test1")
        table.addToTable("test2")
        table.addToTable("test3")
        table.changeHash(SimpleHash())
        assert(table.search("test$number"))
    }

    @Test
    fun delete_emptyTable() {
        val table = HashTable(sizeOfHash, maxLoadFactor, PolynomialHash())
        assertFalse(table.deleteFromTable("test2"))
    }

    @Test
    fun delete_oneElementContained() {
        val table = HashTable(sizeOfHash, maxLoadFactor, PolynomialHash())
        table.addToTable("test2")
        assert(table.deleteFromTable("test2"))
    }

    @ParameterizedTest
    @ValueSource(ints = [1, 2, 3])
    fun delete_manyElements(number: Int) {
        val table = HashTable(sizeOfHash, maxLoadFactor, PolynomialHash())
        table.addToTable("test1")
        table.addToTable("test2")
        table.addToTable("test3")
        for (i in 1..3) {
            if (i != number) {
                table.deleteFromTable("test$i")
            }
        }
        assert(table.search("test$number"))
    }
}

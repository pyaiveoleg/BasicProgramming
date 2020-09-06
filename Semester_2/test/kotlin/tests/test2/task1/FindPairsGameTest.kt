package tests.test2.task1

import org.junit.jupiter.api.Assertions.*
import org.junit.jupiter.api.Test

internal class FindPairsGameTest {
    private val bigSize = 100

    @Test
    fun generateTable_checkSize() {
        val model = FindPairsGame(2)
        assertEquals(model.table.size, 4)
    }

    @Test
    fun generateTable_checkRandom() {
        val size = 2
        val model = FindPairsGame(size)
        val simpleList = MutableList(size) { index -> index / 2 }
        assertNotEquals(model.table, simpleList)
    }

    @Test
    fun generateTable_bigSize() {
        val model = FindPairsGame(bigSize)
        assertEquals(model.table.size, bigSize * bigSize)
    }

    @Test
    fun generateTable_containsAllNumbers() {
        val size = 6
        val model = FindPairsGame(size)
        val table = model.generateTable()
        for (number in 0 until size * size / 2) {
            assert(number in table)
        }
    }

    @Test
    fun generateTable_notContainsOtherNumbers() {
        val size = 6
        val model = FindPairsGame(size)
        val table = model.generateTable()
        for (number in size * size / 2 until size) {
            assert(number !in table)
        }
    }

    @Test
    fun addClick_tooBigCoordinates() {
        val size = 6
        val model = FindPairsGame(size)
        assertThrows(IndexOutOfBoundsException::class.java) {
            model.addClick(size + 1, size + 1)
        }
    }

    @Test
    fun addClick_negativeCoordinates() {
        val size = 6
        val model = FindPairsGame(size)
        assertThrows(IndexOutOfBoundsException::class.java) {
            model.addClick(-1, -1)
        }
    }

    @Test
    fun isEnd_equalClicks() {
        val size = 6
        val quantityOfIterations = 100
        val model = FindPairsGame(size)
        for (i in 0 until quantityOfIterations) {
            model.addClick(0, 0)
        }
        assertFalse(model.isEnd())
    }

    @Test
    fun isEnd_startOfGame() {
        val size = 6
        val model = FindPairsGame(size)
        assertFalse(model.isEnd())
    }

    @Test
    fun isEnd_middleOfGame() {
        val size = 6
        val model = FindPairsGame(size)
        for (x in 0 until size - 1) {
            for (y in 0 until size - 1) {
                model.addClick(x, y)
            }
        }
        assertFalse(model.isEnd())
    }

    @Test
    fun isEnd_simpleTable() {
        val size = 6
        val model = FindPairsGame(size)
        val table = MutableList(size * size) { index -> (index / 2) }
        model.setNewTable(table)
        for (index in 0 until size * size) {
            model.addClick(index % size, index / size)
        }
        assert(model.isEnd())
    }

    @Test
    fun setNewTable_simpleTable() {
        val size = 6
        val model = FindPairsGame(size)
        val table = MutableList(size * size) { index -> (index / 2) }
        model.setNewTable(table)
        assertArrayEquals(model.table.toIntArray(), table.toIntArray())
    }
}
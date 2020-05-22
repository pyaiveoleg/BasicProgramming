package tests.test2.task1

import java.lang.IndexOutOfBoundsException

class FindPairsGame(n: Int) {
    var table = mutableListOf<Int>()
    private var parityOfClicks = 0
    private var firstCell = -1
    private var secondCell = -1
    private var guessedNumbers = mutableListOf<Int>()
    private val size = n

    init {
        generateTable()
    }

    fun generateTable(): MutableList<Int> {
        val listOfNumbers = MutableList(size * size) { index -> (index / 2) }

        for (x in 0 until listOfNumbers.size) {
            listOfNumbers.shuffle()
            table.add(listOfNumbers[0])
            listOfNumbers.removeAt(0)
        }
        return table
    }

    private fun checkNumbers(): List<Int> {
        if (table[firstCell] == table[secondCell]) {
            guessedNumbers.add(firstCell)
            guessedNumbers.add(secondCell)
        }
        return listOf(firstCell, secondCell, table[firstCell], table[secondCell])
    }

    fun addClick(x: Int, y: Int): List<Int> {
        if (x !in 0 until size || y !in 0 until size) {
            throw IndexOutOfBoundsException("Coordinates are invalid")
        }
        if (x + size * y in guessedNumbers) {
            return emptyList()
        }
        parityOfClicks++
        var result = listOf<Int>()
        if (parityOfClicks == 1) {
            firstCell = x + size * y
        }
        if (parityOfClicks == 2) {
            secondCell = x + size * y
            result = checkNumbers()
            firstCell = -1
            secondCell = -1
            parityOfClicks = 0
        }
        return result
    }

    fun isEnd(): Boolean {
        return guessedNumbers.size == size * size
    }

    fun setNewTable(newTable: MutableList<Int>) {
        table = newTable
    }
}

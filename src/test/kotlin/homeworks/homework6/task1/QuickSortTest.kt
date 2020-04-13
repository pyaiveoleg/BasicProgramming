package homeworks.homework6.task1

import kotlinx.coroutines.runBlocking
import org.junit.jupiter.api.Assertions.assertArrayEquals
import org.junit.jupiter.api.Test

private const val SIZE_OF_ARRAY = 100000
private const val MAX_NUMBER = 100000

internal class QuickSortTest {
    @Test
    fun asyncQuickSort_allElementsEqual() {
        val array = intArrayOf(5, 5, 5, 5, 5, 5)
        val expected = intArrayOf(5, 5, 5, 5, 5, 5)
        val arrayLength = array.size - 1
        runBlocking {
            asyncQuickSort(array, 0, arrayLength)
        }
        assertArrayEquals(expected, array)
    }

    @Test
    fun asyncQuickSort_allElementsDifferent() {
        val array = intArrayOf(5, 5, 5, 5, 5, 5)
        val expected = intArrayOf(5, 5, 5, 5, 5, 5)
        val arrayLength = array.size - 1
        runBlocking {
            asyncQuickSort(array, 0, arrayLength)
        }
        assertArrayEquals(expected, array)
    }

    @Test
    fun asyncQuickSort_veryBigRandomArray() {
        val listForSort = mutableListOf<Int>()
        for (i in 0 until SIZE_OF_ARRAY) {
            listForSort.add((0..MAX_NUMBER).random())
        }
        val array = listForSort.toIntArray()
        val expected = array.sorted().toIntArray()
        val arrayLength = array.size - 1
        runBlocking {
            asyncQuickSort(array, 0, arrayLength)
        }
        assertArrayEquals(expected, array)
    }

    @Test
    fun asyncQuickSort_veryBigAscendingArray() {
        val listForSort = mutableListOf<Int>()
        for (i in 0 until SIZE_OF_ARRAY) {
            listForSort.add(i)
        }
        val array = listForSort.toIntArray()
        val expected = array.sorted().toIntArray()
        val arrayLength = array.size - 1
        runBlocking {
            asyncQuickSort(array, 0, arrayLength)
        }
        assertArrayEquals(expected, array)
    }

    @Test
    fun asyncQuickSort_veryBigDescendingArray() {
        val listForSort = mutableListOf<Int>()
        for (i in 0 until SIZE_OF_ARRAY) {
            listForSort.add(SIZE_OF_ARRAY - i)
        }
        val array = listForSort.toIntArray()
        val expected = array.sorted().toIntArray()
        val arrayLength = array.size - 1
        runBlocking {
            asyncQuickSort(array, 0, arrayLength)
        }
        assertArrayEquals(expected, array)
    }
}

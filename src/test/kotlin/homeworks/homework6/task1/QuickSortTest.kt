package homeworks.homework6.task1

import kotlinx.coroutines.launch
import kotlinx.coroutines.runBlocking
import org.junit.jupiter.api.Assertions.assertArrayEquals
import org.junit.jupiter.api.Test

internal class QuickSortTest {
    private val sizeOfArray = 10000
    private val maxNumber = 100000

    @Test
    fun simpleQuickSort_allElementsEqual() {
        val array = intArrayOf(5, 5, 5, 5, 5, 5)
        val expected = intArrayOf(5, 5, 5, 5, 5, 5)
        val arrayLength = array.size - 1
        QuickSort().simpleQuickSort(array, 0, arrayLength)
        assertArrayEquals(expected, array)
    }

    @Test
    fun asyncQuickSort_allElementsEqual() {
        val array = intArrayOf(5, 5, 5, 5, 5, 5)
        val expected = intArrayOf(5, 5, 5, 5, 5, 5)
        val arrayLength = array.size - 1
        runBlocking {
            QuickSort().asyncQuickSort(array, 0, arrayLength)
        }
        assertArrayEquals(expected, array)
    }

    @Test
    fun simpleQuickSort_allElementsDifferent() {
        val array = intArrayOf(5, 5, 5, 5, 5, 5)
        val expected = intArrayOf(5, 5, 5, 5, 5, 5)
        val arrayLength = array.size - 1
        QuickSort().simpleQuickSort(array, 0, arrayLength)
        assertArrayEquals(expected, array)
    }

    @Test
    fun asyncQuickSort_allElementsDifferent() {
        val array = intArrayOf(5, 5, 5, 5, 5, 5)
        val expected = intArrayOf(5, 5, 5, 5, 5, 5)
        val arrayLength = array.size - 1
        runBlocking {
            QuickSort().asyncQuickSort(array, 0, arrayLength)
        }
        assertArrayEquals(expected, array)
    }

    @Test
    fun simpleQuickSort_veryBigRandomArray() {
        val array = IntArray(sizeOfArray) { (0..maxNumber).random() }
        val expected = array.sorted().toIntArray()
        val arrayLength = array.size - 1
        QuickSort().simpleQuickSort(array, 0, arrayLength)
        assertArrayEquals(expected, array)
    }

    @Test
    fun asyncQuickSort_veryBigRandomArray() {
        val array = IntArray(sizeOfArray) { (0..maxNumber).random() }
        val expected = array.sorted().toIntArray()
        val arrayLength = array.size - 1
        runBlocking {
            launch {
                QuickSort().asyncQuickSort(array, 0, arrayLength)
            }
        }
        assertArrayEquals(expected, array)
    }

    @Test
    fun simpleQuickSort_veryBigAscendingArray() {
        val array = IntArray(sizeOfArray) { it }
        val expected = array.sorted().toIntArray()
        val arrayLength = array.size - 1
        QuickSort().simpleQuickSort(array, 0, arrayLength)
        assertArrayEquals(expected, array)
    }

    @Test
    fun asyncQuickSort_veryBigAscendingArray() {
        val array = IntArray(sizeOfArray) { it }
        val expected = array.sorted().toIntArray()
        val arrayLength = array.size - 1
        runBlocking {
            QuickSort().asyncQuickSort(array, 0, arrayLength)
        }
        assertArrayEquals(expected, array)
    }

    @Test
    fun simpleQuickSort_veryBigDescendingArray() {
        val array = IntArray(sizeOfArray) { sizeOfArray - it }
        val expected = array.sorted().toIntArray()
        val arrayLength = array.size - 1
        QuickSort().simpleQuickSort(array, 0, arrayLength)
        assertArrayEquals(expected, array)
    }

    @Test
    fun asyncQuickSort_veryBigDescendingArray() {
        val array = IntArray(sizeOfArray) { sizeOfArray - it }
        val expected = array.sorted().toIntArray()
        val arrayLength = array.size - 1
        runBlocking {
            QuickSort().asyncQuickSort(array, 0, arrayLength)
        }
        assertArrayEquals(expected, array)
    }
}

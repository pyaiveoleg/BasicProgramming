package homeworks.homework6.task1

import kotlinx.coroutines.coroutineScope
import kotlin.system.measureTimeMillis

private const val SIZE_OF_ARRAY = 10000000
private const val MAX_NUMBER = 100000

suspend fun main() {
    val listForSort = mutableListOf<Int>()
    for (i in 0 until SIZE_OF_ARRAY) {
        listForSort.add((0..MAX_NUMBER).random())
    }
    val arrayForSort = listForSort.toIntArray()
    val timeUsualRealization = measureTimeMillis {
        quickSort(arrayForSort, 0, arrayForSort.size - 1)
    }
    println("Time of usual realization is $timeUsualRealization")

    val arrayForAsyncSort = listForSort.toIntArray()
    launchQuickSortAndPrintTime(arrayForAsyncSort)
}

suspend fun launchQuickSortAndPrintTime(arrayForAsyncSort: IntArray) = coroutineScope {
    val timeAsyncRealization = measureTimeMillis {
        asyncQuickSort(arrayForAsyncSort, 0, arrayForAsyncSort.size - 1)
    }
    println("Time of async realization is $timeAsyncRealization")
}

suspend fun asyncQuickSort(array: IntArray, left: Int, right: Int) {
    val sample = array[(left + right) / 2]
    var i = left
    var j = right
    do {
        while (array[i] < sample) {
            i++
        }
        while (array[j] > sample) {
            j--
        }
        if (i <= j) {
            if (array[i] > array[j]) {
                swap(i, j, array)
            }
            i++
            if (j > 0) {
                j--
            }
        }
    } while (i <= j)
    if (i < right) {
        asyncQuickSort(array, i, right)
    }
    if (j > left) {
        asyncQuickSort(array, left, j)
    }
}

fun swap(firstElement: Int, secondElement: Int, array: IntArray) {
    val temporary = array[firstElement]
    array[firstElement] = array[secondElement]
    array[secondElement] = temporary
}

fun quickSort(array: IntArray, left: Int, right: Int) {
    val sample = array[(left + right) / 2]
    var i = left
    var j = right
    do {
        while (array[i] < sample) {
            i++
        }
        while (array[j] > sample) {
            j--
        }
        if (i <= j) {
            if (array[i] > array[j]) {
                swap(i, j, array)
            }
            i++
            if (j > 0) {
                j--
            }
        }
    } while (i <= j)
    if (i < right) {
        quickSort(array, i, right)
    }
    if (j > left) {
        quickSort(array, left, j)
    }
}

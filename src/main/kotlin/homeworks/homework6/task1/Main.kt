package homeworks.homework6.task1

import kotlinx.coroutines.launch
import kotlinx.coroutines.runBlocking
import java.io.File
import kotlin.system.measureTimeMillis

class Main {
    private val sizeOfArray = 10000000
    private val maxNumber = 100000
    private val quantityOfAttempts = 10

    fun printComparingBetweenSorts() {
        val resultingFile = File("result.txt")
        val writer = resultingFile.bufferedWriter()
        for (i in 1..quantityOfAttempts) {
            writer.write("Attempt: $i\n")
            val quickSortClass = QuickSort()
            val array = IntArray(sizeOfArray) { (0..maxNumber).random() }
            val arrayForSort = array.clone()
            val timeUsualRealization = measureTimeMillis {
                quickSortClass.simpleQuickSort(arrayForSort, 0, arrayForSort.size - 1)
            }
            writer.write("Time of usual realization is $timeUsualRealization\n")

            val arrayForAsyncSort = array.clone()
            var timeAsyncRealization: Long = 0
            runBlocking {
                launch {
                    timeAsyncRealization = measureTimeMillis {
                        quickSortClass.asyncQuickSort(arrayForAsyncSort, 0, arrayForAsyncSort.size - 1)
                    }
                }
            }
            writer.write("Time of async realization is $timeAsyncRealization\n\n")
        }
        writer.flush()
    }
}

fun main() {
    Main().printComparingBetweenSorts()
}

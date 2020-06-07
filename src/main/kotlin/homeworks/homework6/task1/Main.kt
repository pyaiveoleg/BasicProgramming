package homeworks.homework6.task1

import kotlinx.coroutines.launch
import kotlinx.coroutines.runBlocking
import kotlin.system.measureTimeMillis
import java.io.File

private const val SIZE_OF_ARRAY = 10000000
private const val MAX_NUMBER = 100000

fun main() {
    val resultingFile = File("result.txt") // чего-то он пустой
    val writer = resultingFile.bufferedWriter()
    for (i in 1..10) {
        writer.write("Attempt: $i\n")
        val quickSortClass = QuickSort()
        val array = IntArray(SIZE_OF_ARRAY) { (0..MAX_NUMBER).random() }
        val arrayForSort = array.clone()
        val timeUsualRealization = measureTimeMillis {
            quickSortClass.quickSort(arrayForSort, 0, arrayForSort.size - 1)
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

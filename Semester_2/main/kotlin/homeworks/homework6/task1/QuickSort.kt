package homeworks.homework6.task1

class QuickSort {
    suspend fun asyncQuickSort(array: IntArray, left: Int, right: Int) {
        if (left < right) {
            val middle = splitArray(array, left, right)
            asyncQuickSort(array, middle + 1, right)
            asyncQuickSort(array, left, middle)
        }
    }

    fun simpleQuickSort(array: IntArray, left: Int, right: Int) {
        if (left < right) {
            val middle = splitArray(array, left, right)
            simpleQuickSort(array, middle + 1, right)
            simpleQuickSort(array, left, middle)
        }
    }

    private fun swap(firstElement: Int, secondElement: Int, array: IntArray) {
        array[firstElement] = array[secondElement].also { array[secondElement] = array[firstElement] }
    }

    private fun splitArray(array: IntArray, left: Int, right: Int): Int {
        val pivot = array[(left + right) / 2]
        var i = left
        var j = right

        while (i <= j) {
            while (array[i] < pivot) {
                i++
            }
            while (array[j] > pivot) {
                j--
            }

            if (i >= j) {
                break
            }

            if (array[i] > array[j]) {
                swap(i, j, array)
            }
            i++
            j--
        }
        return j
    }
}

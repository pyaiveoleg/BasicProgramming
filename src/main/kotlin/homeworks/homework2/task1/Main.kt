package homeworks.homework2.task1

import java.util.*

fun removeRepeatingElements(originalArray: Array<Int>): Array<Int> {
    return originalArray.distinct().toTypedArray()
}

fun main() {
    val scan = Scanner(System.`in`)
    println("Please, write down quantity of numbers in your array:")
    val arrayLength = scan.nextInt()
    val originalList = Array(arrayLength) { 0 }
    println("Please, write down list of integer values:")
    for (i in 0 until arrayLength) {
        originalList[i] = scan.nextInt()
    }
    println("This is distincted list:\n" + removeRepeatingElements(originalList))
}

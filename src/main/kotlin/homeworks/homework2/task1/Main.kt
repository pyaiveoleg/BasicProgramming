package homeworks.homework2.task1

import java.util.Scanner

fun removeRepeatingElements(originalArray: IntArray): IntArray {
    return originalArray.distinct().toIntArray()
}

fun main() {
    val scan = Scanner(System.`in`)
    println("Please, write down quantity of numbers in your array:")
    val arrayLength = scan.nextInt()
    val originalArray = Array(arrayLength) { 0 }.toIntArray()
    println("Please, write down list of integer values:")
    for (i in 0 until arrayLength) {
        originalArray[i] = scan.nextInt()
    }
    println("This is distincted list:\n" + removeRepeatingElements(originalArray))
}

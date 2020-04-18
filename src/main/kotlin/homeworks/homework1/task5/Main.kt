package homeworks.homework1.task5

import java.io.File
import java.io.InvalidObjectException

fun countNotEmptyStrings(input: File): Int {
    var quantityOfNotEmptyStrings = 0

    if (!input.exists()) {
        throw InvalidObjectException("Error. Cannot open file.")
    }

    for (inputString in input.readLines()) {
        if (!inputString.isBlank()) {
            quantityOfNotEmptyStrings++
        }
    }
    return quantityOfNotEmptyStrings
}

fun main() {
    val input = File("./src/main/resources/homeworks/homework1/task1/input.txt")
    try {
        print("Quantity of not-empty strings in the file: ${countNotEmptyStrings(input)}")
    } catch (exception: InvalidObjectException) {
        print("Error. Cannot open file.")
    }
}

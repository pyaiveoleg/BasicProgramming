package homeworks.homework1.task5

import java.io.File
import java.io.InvalidObjectException

fun countNotEmptyStrings(input: File): Int {
    var quantityOfNotEmptyStrings = 0
    var isEmpty = true

    if (!input.exists()) {
        throw InvalidObjectException("Error. Cannot open file.")
    }

    for (inputString in input.readLines()) {
        val stringLength = inputString.length

        for (j in 0..stringLength - 1) {
            if ((inputString[j] != ' ') && (inputString[j] != '\t')) {
                isEmpty = false
            }
        }

        if (!isEmpty && stringLength > 0) {
            quantityOfNotEmptyStrings++
        }
        isEmpty = true
    }
    return quantityOfNotEmptyStrings
}

fun main() {
    val input = File("./src/main/resources/input.txt")
    try {
        print("Quantity of not-empty strings in the file: ${countNotEmptyStrings(input)}")
    } catch (exception: InvalidObjectException) {
        print("Error. Cannot open file.")
    }
}

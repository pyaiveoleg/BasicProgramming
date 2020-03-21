package homeworks.homework1.task3

fun countInclusions(inputString: String?, pattern: String?): Int {
    if (inputString == null || pattern == null) {
        throw IllegalArgumentException("String must not be null.")
    }

    val patternLength = pattern.length
    val stringLength = inputString.length
    var isIncluded = true
    var quantityOfInclusions = 0

    for (i in 0..stringLength - patternLength) {
        for (j in 0..patternLength - 1) {
            if (pattern[j] != inputString[i + j]) {
                isIncluded = false
                break
            }
        }
        if (isIncluded) {
            quantityOfInclusions++
        } else {
            isIncluded = true
        }
    }
    return quantityOfInclusions
}

fun main() {
    println("Please, write down pattern (s1):")
    val pattern = readLine()
    println("Please, write down string (s2):")
    val inputString = readLine()

    try {
        val quantityOfInclusions = countInclusions(inputString, pattern)
        println("This is a number of inclusions s1 in s2: $quantityOfInclusions")
    } catch (exception: IllegalArgumentException) {
        print("String must not be empty.")
    }
}

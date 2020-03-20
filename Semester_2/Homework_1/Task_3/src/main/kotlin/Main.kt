val scan = java.util.Scanner(System.`in`)

fun countInclusions(inputString: String, pattern: String): Int {
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
    println("Please, write down pattern (s1): ")
    val pattern = scan.nextLine()
    println("Please, write down string (s2): ")
    val inputString = scan.nextLine()

    val quantityOfInclusions = countInclusions(inputString, pattern)
    println("This is a number of inclusions s1 in s2: ${quantityOfInclusions}")
}

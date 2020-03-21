package homeworks.homework2.task2

fun countQuantityOfSymbolsToDelete(inputString: String): Int {
    var quantityOfSymbolsToDelete = 0
    val regex = "x+".toRegex()
    var match: MatchResult? = regex.find(inputString) ?: return 0

    while (match != null) {
        val lengthOfSubsequence = match.range.last - match.range.first + 1
        if (lengthOfSubsequence > 2) {
            quantityOfSymbolsToDelete += lengthOfSubsequence - 2
        }
        match = match.next()
    }
    return quantityOfSymbolsToDelete
}

fun main() {
    println("Please, write down original string:")
    val inputString = readLine()!!

    val quantityOfSymbolsToDelete = countQuantityOfSymbolsToDelete(inputString)

    println("This is quantity of elements to delete from original string when it will not contain \"xxx\" string")
    println(quantityOfSymbolsToDelete)
}

package homeworks.homework2.task1

fun countQuantityOfSymbolsToDelete(inputString: String, quantityOfForbiddenX: Int = 3): Int {
    var quantityOfSymbolsToDelete = 0
    val regex = "+".padStart(quantityOfForbiddenX + 1, 'x').toRegex()
    val illegalSubstrings = regex.findAll(inputString)
    for (match in illegalSubstrings) {
        quantityOfSymbolsToDelete += match.value.length + 1 - quantityOfForbiddenX
    }
    return quantityOfSymbolsToDelete
}

fun main() {
    println("Please, write down original string:")
    val inputString = readLine() ?: run {
        print("String cannot be null.")
        return
    }

    val quantityOfSymbolsToDelete = countQuantityOfSymbolsToDelete(inputString)

    println("This is quantity of elements to delete from original string when it will not contain \"xxx\" string")
    println(quantityOfSymbolsToDelete)
}

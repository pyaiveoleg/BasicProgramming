package homeworks.homework4.task1

import java.io.File
import kotlin.math.pow

private const val CODE_OF_HELP = 0
private const val CODE_OF_ADD = 1
private const val CODE_OF_SEARCH = 2
private const val CODE_OF_REMOVE = 3
private const val CODE_OF_CHANGE_HASH = 4
private const val CODE_OF_PRINT_STATISTICS = 5
private const val CODE_OF_IMPORT = 6
private const val CODE_OF_EXIT = 7
private const val SIZE_OF_HASH = 1000
private const val MAX_LOAD_FACTOR = 0.9

fun main() {
    val hashTable = HashTable(SIZE_OF_HASH, MAX_LOAD_FACTOR) { string: String -> calculatePolynomialHash(string) }

    workWithTable(hashTable)
}

private fun calculateSimpleHash(string: String): Int {
    var hash = 0
    for (character in string) {
        hash += character.toInt()
    }
    return hash
}

fun calculatePolynomialHash(string: String): Int {
    val bigPrimaryNumber = 1000000009.0
    var hash = 0
    var index = 0
    for (character in string) {
        hash += (character.toInt() * bigPrimaryNumber.pow(index)).toInt()
        index++
    }
    return hash
}

fun printHelp() {
    println("$CODE_OF_HELP - show help")
    println("$CODE_OF_ADD - add value to table")
    println("$CODE_OF_SEARCH - find value in the table")
    println("$CODE_OF_REMOVE - remove value from table")
    println("$CODE_OF_CHANGE_HASH - change hash-function (from list of built-in functions)")
    println("$CODE_OF_PRINT_STATISTICS - show statistics")
    println("$CODE_OF_IMPORT - import table from file")
    println("$CODE_OF_EXIT - exit")
}

fun changeHash(codeOfHash: Int): (String) -> Int {
    if (codeOfHash == 1) {
        return { string: String -> calculatePolynomialHash(string) }
    } else {
        return { string: String -> calculateSimpleHash(string) }
    }
}

fun workWithTable(hashTable: HashTable) {
    println("Type '$CODE_OF_HELP' for list of commands.")
    while (true) {
        when (readLine()?.toInt() ?: 0) {
            CODE_OF_HELP -> printHelp()
            CODE_OF_ADD -> {
                println("Write down value for adding:")
                hashTable.addToTable(readLine())
                println("Successfully added")
            }
            CODE_OF_SEARCH -> {
                println("Write down value for search:")
                if (hashTable.search(readLine())) {
                    println("This string is in table")
                } else {
                    println("This string is not in table")
                }
            }
            CODE_OF_REMOVE -> {
                println("Write down value to remove")
                hashTable.deleteFromTable(readLine())
                println("Successfully deleted")
            }
            CODE_OF_CHANGE_HASH -> {
                print("Choose hash-function: 1 for polynomial hash, 2 for simple hash")
                val hashFunction =
                    changeHash(readLine()?.toInt() ?: throw IllegalArgumentException("invalid code of hash"))
                hashTable.changeHash(hashFunction)
            }
            CODE_OF_PRINT_STATISTICS -> {
                hashTable.printStatistics()
            }
            CODE_OF_IMPORT -> {
                val inputFile = File("./src/resources/kotlin/homeworks/homework4/task1/testFile.txt")
                for (string in inputFile.readLines()) {
                    hashTable.addToTable(string)
                }
            }
            CODE_OF_EXIT -> return
        }
    }
}

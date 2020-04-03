package homeworks.homework4.task1

import java.io.File
import kotlin.math.pow

fun main() {
    val sizeOfHash = 1000
    val maxLoadFactor = 0.9
    val hashTable = HashTable(sizeOfHash, maxLoadFactor) { string: String -> calculatePolynomialHash(string) }

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
    println("0 - show help")
    println("1 - add value to table")
    println("2 - find value in the table")
    println("3 - remove value from table")
    println("4 - change hash-function (from list of built-in functions)")
    println("5 - show statistics")
    println("6 - import table from file")
    println("7 - exit")
}

fun changeHash(codeOfHash: Int): (String) -> Int {
    if (codeOfHash == 1) {
        return { string: String -> calculatePolynomialHash(string) }
    } else {
        return { string: String -> calculateSimpleHash(string) }
    }
}

fun workWithTable(hashTable: HashTable) {
    println("Type '0' for list of commands.")
    val codeOfHelp = 0
    val codeOfAdd = 1
    val codeOfSearch = 2
    val codeOfRemove = 3
    val codeOfChangeHash = 4
    val codeOfPrintStatistics = 5
    val codeOfImport = 6
    val codeOfExit = 7

    while (true) {
        when (readLine()?.toInt() ?: 0) {
            codeOfHelp -> printHelp()
            codeOfAdd -> {
                println("Write down value for adding:")
                hashTable.addToTable(readLine())
                println("Successfully added")
            }
            codeOfSearch -> {
                println("Write down value for search:")
                if (hashTable.search(readLine())) {
                    println("This string is in table")
                } else {
                    println("This string is not in table")
                }
            }
            codeOfRemove -> {
                println("Write down value to remove")
                hashTable.deleteFromTable(readLine())
                println("Successfully deleted")
            }
            codeOfChangeHash -> {
                print("Choose hash-function: 1 for polynomial hash, 2 for simple hash")
                val hashFunction =
                    changeHash(readLine()?.toInt() ?: throw IllegalArgumentException("invalid code of hash"))
                hashTable.changeHash(hashFunction)
            }
            codeOfPrintStatistics -> {
                hashTable.printStatistics()
            }
            codeOfImport -> {
                val inputFile = File("./src/resources/kotlin/homeworks/homework4/task1/testFile.txt")
                for (string in inputFile.readLines()) {
                    hashTable.addToTable(string)
                }
            }
            codeOfExit -> return
        }
    }
}

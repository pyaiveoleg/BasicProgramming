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
    val bigPrimaryNumber = (10.0.pow(9.0) + 9)
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
    while (true) {
        when (readLine()?.toInt() ?: 0) {
            0 -> printHelp()
            1 -> {
                println("Write down value for adding:")
                hashTable.addToTable(readLine())
                println("Successfully added")
            }
            2 -> {
                println("Write down value for search:")
                if (hashTable.search(readLine())) {
                    println("This string is in table")
                } else {
                    println("This string is not in table")
                }
            }
            3 -> {
                println("Write down value to remove")
                hashTable.deleteFromTable(readLine())
                println("Successfully deleted")
            }
            4 -> {
                print("Choose hash-function: 1 for polynomial hash, 2 for simple hash")
                val hashFunction =
                    changeHash(readLine()?.toInt() ?: throw IllegalArgumentException("invalid code of hash"))
                hashTable.changeHash(hashFunction)
            }
            5 -> {
                hashTable.printStatistics()
            }
            6 -> {
                val inputFile = File("./src/resources/kotlin/homeworks/homework4/task1/testFile.txt")
                for (string in inputFile.readLines()) {
                    hashTable.addToTable(string)
                }
            }
            7 -> return
        }
    }
}

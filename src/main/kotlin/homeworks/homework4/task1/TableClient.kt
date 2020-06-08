package homeworks.homework4.task1

import java.io.File

class TableClient {
    companion object Config {
        private const val CODE_OF_HELP = 0
        private const val CODE_OF_ADD = 1
        private const val CODE_OF_SEARCH = 2
        private const val CODE_OF_REMOVE = 3
        private const val CODE_OF_CHANGE_HASH = 4
        private const val CODE_OF_PRINT_STATISTICS = 5
        private const val CODE_OF_IMPORT = 6
        private const val CODE_OF_EXIT = 7

        const val SIZE_OF_HASH = 1000
        const val MAX_LOAD_FACTOR = 0.9
    }

    private fun printHelp() {
        println("$CODE_OF_HELP - show help")
        println("$CODE_OF_ADD - add value to table")
        println("$CODE_OF_SEARCH - find value in the table")
        println("$CODE_OF_REMOVE - remove value from table")
        println("$CODE_OF_CHANGE_HASH - change hash-function (from list of built-in functions)")
        println("$CODE_OF_PRINT_STATISTICS - show statistics")
        println(
            "$CODE_OF_IMPORT - import table from file \"./src/main/resources/homeworks/homework4/task1/testFile.txt\""
        )
        println("$CODE_OF_EXIT - exit")
    }

    private fun changeHash(codeOfHash: Int): HashFunction {
        return if (codeOfHash == 1) {
            PolynomialHash()
        } else {
            SimpleHash()
        }
    }

    private fun readCodeAndChangeHash(hashTable: HashTable) {
        println("Choose hash-function: 1 for polynomial hash, 2 for simple hash")
        val codeOfHash = try {
            readLine()?.toInt()
        } catch (exception: NumberFormatException) {
            0
        }
        if (codeOfHash == 1 || codeOfHash == 2) {
            val hashFunction = changeHash(codeOfHash)
            hashTable.changeHash(hashFunction)
            println("Hash changed successfully!")
        } else {
            println("Invalid code of hash")
        }
    }

    private fun readCommand(): Int {
        return try {
            readLine()?.toInt() ?: CODE_OF_HELP
        } catch (e: NumberFormatException) {
            CODE_OF_HELP
        }
    }

    private fun addElement(hashTable: HashTable) {
        println("Write down value for adding:")
        val stringToAdd = readLine()
        if (stringToAdd == null) {
            println("String cannot be null")
        }

        if (hashTable.addToTable(stringToAdd)) {
            println("Successfully added")
        } else {
            println("String is already in table")
        }
    }

    fun workWithTable(hashTable: HashTable) {
        println("Type '$CODE_OF_HELP' for list of commands.")
        while (true) {
            when (readCommand()) {
                CODE_OF_HELP -> printHelp()
                CODE_OF_ADD -> {
                    addElement(hashTable)
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
                    if (hashTable.deleteFromTable(readLine())) {
                        println("Successfully deleted")
                    } else {
                        println("There aren't such string in table")
                    }
                }
                CODE_OF_CHANGE_HASH -> {
                    readCodeAndChangeHash(hashTable)
                }
                CODE_OF_PRINT_STATISTICS -> {
                    hashTable.printStatistics()
                }
                CODE_OF_IMPORT -> {
                    val inputFile = File("./src/main/resources/homeworks/homework4/task1/testFile.txt")
                    for (string in inputFile.readLines()) {
                        hashTable.addToTable(string)
                    }
                    println("Table has been imported successfully!")
                }
                CODE_OF_EXIT -> return
                else -> println("Invalid command")
            }
        }
    }
}

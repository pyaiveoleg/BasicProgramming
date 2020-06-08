package homeworks.homework4.task1

fun main() {
    val hashTable = HashTable(TableClient.SIZE_OF_HASH, TableClient.MAX_LOAD_FACTOR, PolynomialHash())
    TableClient().workWithTable(hashTable)
}


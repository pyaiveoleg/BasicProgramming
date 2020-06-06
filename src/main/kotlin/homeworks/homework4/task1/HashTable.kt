package homeworks.homework4.task1

import kotlin.math.abs

private const val VALUE_FOR_EXPAND = 2

class HashTable(
    private var sizeOfHash: Int,
    private var maxLoadFactor: Double,
    private var hashFunction: HashFunction
) {
    private var quantityOfRecords = 0
    private var quantityOfFilledBuckets = 0
    private var array = Array(sizeOfHash) { Record(mutableListOf()) }

    data class Record(val key: MutableList<String>)

    private fun redistributeElements() {
        quantityOfFilledBuckets = 0
        quantityOfRecords = 0
        val oldArray = this.array
        array = Array(sizeOfHash) { Record(mutableListOf()) }
        for (record in oldArray) {
            for (item in record.key) {
                addToTable(item)
            }
        }
    }

    private fun expandHashTable() {
        sizeOfHash *= VALUE_FOR_EXPAND
        redistributeElements()
    }

    fun addToTable(string: String?) {
        if (string == null) {
            return
        }
        val hash = abs(hashFunction.calculateHash(string)) % sizeOfHash
        val bucket = array[hash]
        if (string in bucket.key) {
            return
        }
        if (bucket.key.size == 0) {
            quantityOfFilledBuckets++
        }
        bucket.key.add(string)
        quantityOfRecords++
        if (quantityOfRecords.toDouble() / sizeOfHash > maxLoadFactor) {
            expandHashTable()
        }
    }

    fun deleteFromTable(string: String?): Boolean {
        if (string == null || !search(string)) {
            return false
        }
        val hash = abs(hashFunction.calculateHash(string)) % sizeOfHash
        val bucket = array[hash]
        bucket.key.remove(string)
        if (bucket.key.size == 0) {
            quantityOfFilledBuckets--
        }
        quantityOfRecords--
        return true
    }

    fun search(string: String?): Boolean {
        if (string == null) {
            return false
        }
        val hash = abs(hashFunction.calculateHash(string)) % sizeOfHash
        return string in array[hash].key
    }

    fun printStatistics() {
        var quantityOfConflicts = 0
        var maxElementsInConflictBucket = 0
        for (i in 0 until sizeOfHash) {
            if (array[i].key.size > 1) {
                quantityOfConflicts++
            }
            if (array[i].key.size > maxElementsInConflictBucket) {
                maxElementsInConflictBucket = array[i].key.size
            }
        }

        println("Quantity of filled buckets is $quantityOfFilledBuckets")
        println("Quantity of items is $quantityOfRecords")
        println("Load factor is ${quantityOfRecords.toDouble() / sizeOfHash}")
        println("Quantity of conflicts is $quantityOfConflicts")
        println("Maximum length of list in bucket with conflict is $maxElementsInConflictBucket")
        println("Quantity of empty buckets is ${sizeOfHash - quantityOfFilledBuckets}")
    }

    fun changeHash(hashFunction: HashFunction) {
        this.hashFunction = hashFunction
        redistributeElements()
    }
}

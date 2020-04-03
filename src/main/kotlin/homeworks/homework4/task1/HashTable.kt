package homeworks.homework4.task1

import kotlin.math.abs

class HashTable(private var sizeOfHash: Int, private var maxLoadFactor: Double, functionForHash: (String) -> Int) {
    private var quantityOfRecords = 0
    private var quantityOfFilledBuckets = 0
    private var array = Array(sizeOfHash) { Record() }
    private var calculateHash = functionForHash

    class Record {
        val key = mutableListOf<String>()
        var quantityOfEntries = 0
    }

    private fun redistributeElements() {
        val oldArray = this.array
        array = Array(sizeOfHash) { Record() }
        for (record in oldArray) {
            for (item in record.key) {
                addToTable(item)
            }
        }
    }

    private fun expandHashTable() {
        val valueForExpand = 2
        sizeOfHash *= valueForExpand
        redistributeElements()
    }

    fun addToTable(string: String?) {
        if (string == null) {
            return
        }
        val hash = abs(calculateHash(string)) % sizeOfHash
        val bucket = array[hash]
        if (string in bucket.key) {
            return
        }
        if (bucket.key.size == 0) {
            quantityOfFilledBuckets++
        }
        bucket.key.add(string)
        bucket.quantityOfEntries++
        quantityOfRecords++
        if (quantityOfRecords / sizeOfHash > maxLoadFactor) {
            expandHashTable()
        }
    }

    fun deleteFromTable(string: String?) {
        if (string == null) {
            return
        }
        val hash = abs(calculateHash(string)) % sizeOfHash
        val bucket = array[hash]
        bucket.key.remove(string)
        bucket.quantityOfEntries--
        if (bucket.key.size == 0) {
            quantityOfFilledBuckets--
        }
        quantityOfRecords--
    }

    fun search(string: String?): Boolean {
        if (string == null) {
            return false
        }
        val hash = abs(calculateHash(string)) % sizeOfHash
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
        println("Load factor is ${quantityOfFilledBuckets.toDouble() / sizeOfHash}")
        println("Quantity of conflicts is $quantityOfConflicts")
        println("Maximum length of list in bucket with conflict is $maxElementsInConflictBucket")
        println("Quantity of empty buckets is ${sizeOfHash - quantityOfFilledBuckets}")
    }

    fun changeHash(hashFunction: (String) -> Int) {
        this.calculateHash = hashFunction
        redistributeElements()
    }
}

package tests.test_1.task_1

import java.io.InvalidObjectException

class PriorityQueue {
    private var size = 0
    val list = mutableListOf<Int>()
    val values = mutableListOf<Any>()

    public fun enqueue(value: Any, priority: Int) {
        this.size += 1
        list.add(priority)
        values.add(value)
        var currentElement = this.size - 1
        var parent = (currentElement - 1) / 2
        while (currentElement > 0 && list.get(parent) > list.get(currentElement)) {
            swap(this.list.toMutableList(), currentElement, parent)
            swap(values, currentElement, parent)
            currentElement = parent
            parent = (currentElement - 1) / 2
        }
    }

    private fun swap(list: MutableList<Any>, firstIndex: Int, secondIndex: Int)
    {
        val temp = list.get(firstIndex)
        list.set(firstIndex, list.get(secondIndex))
        list.set(secondIndex, temp)
    }

    public fun dequeue() : Any {
        if (this.isEmpty())
        {
            throw InvalidObjectException("Queue is empty")
        }
        val value = this.values[this.size - 1]
        this.list.removeAt(this.size - 1)
        this.values.removeAt(this.size - 1)
        this.size -= 1
        return value
    }

    private fun isEmpty() : Boolean {
        return this.size == 0
    }

    public fun printQueue()
    {
        print(this.values.toString())
    }
}
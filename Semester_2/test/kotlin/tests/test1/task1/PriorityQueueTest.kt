package tests.test1.task1

import org.junit.jupiter.api.Assertions.assertEquals
import org.junit.jupiter.api.Assertions.assertThrows
import org.junit.jupiter.api.Test
import java.io.InvalidObjectException

internal class PriorityQueueTest {
    @Test
    fun enqueue_emptyQueue() {
        val testQueue = PriorityQueue()
        testQueue.enqueue(1, 100)
        assertEquals(testQueue.values[0], 1)
    }

    @Test
    fun enqueue_queueWithOneElement() {
        val testQueue = PriorityQueue()
        testQueue.enqueue(1, 100)
        testQueue.enqueue(2, 99)
        assertEquals(testQueue.values[1], 1)
    }

    @Test
    fun enqueue_bigQueue() {
        val testQueue = PriorityQueue()
        for (i in 1..10000) {
            testQueue.enqueue(i, i)
        }
        assertEquals(testQueue.list[9999], 10000)
    }

    @Test
    fun enqueue_queueWithDifferentObjects() {
        val testQueue = PriorityQueue()
        testQueue.enqueue("String", 7)
        testQueue.enqueue(5, 8)
        testQueue.enqueue(arrayListOf(0, 1, 2, 3), 8)
        assertEquals(testQueue.values[0], "String")
    }

    @Test
    fun enqueue_queueWithOneDeletionAndAddingAfter() {
        val testQueue = PriorityQueue()
        testQueue.enqueue("String", 7)
        testQueue.enqueue(5, 8)
        testQueue.enqueue(arrayListOf(0, 1, 2, 3), 10)
        testQueue.dequeue()
        testQueue.enqueue(10, 9)
        assertEquals(testQueue.values[0], "String")
    }

    @Test
    fun enqueue_equalPriorities() {
        val testQueue = PriorityQueue()
        testQueue.enqueue(1, 7)
        testQueue.enqueue(2, 7)
        assertEquals(testQueue.values[0], 1)
    }

    @Test
    fun dequeue_emptyQueue() {
        val testQueue = PriorityQueue()
        assertThrows(InvalidObjectException::class.java) {
            testQueue.dequeue()
        }
    }

    @Test
    fun dequeue_queueWithOneElement() {
        val testQueue = PriorityQueue()
        testQueue.enqueue(1, 1)
        assertEquals(testQueue.dequeue(), 1)
    }

    @Test
    fun dequeue_queueWithManyElements() {
        val testQueue = PriorityQueue()
        for (i in 1..10000) {
            testQueue.enqueue(i, i)
        }
        assertEquals(testQueue.dequeue(), 10000)
    }
}
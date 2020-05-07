package homeworks.homework1.task1

import org.junit.jupiter.api.Assertions.*
import org.junit.jupiter.api.Test
import java.lang.IllegalArgumentException

private const val BIG_ARRAY_LENGTH = 100000

internal class MainTest {
    @Test
    fun exchangeStartAndEnd_usualCase() {
        val expected = mutableListOf(1, 2, 3, 4, 5, 6)
        val actual = mutableListOf(5, 6, 1, 2, 3, 4)
        assertEquals(actual, exchangeStartAndEnd(4, 2, expected))
    }

    @Test
    fun exchangeStartAndEnd_endingIsZero() {
        val expected = mutableListOf(1, 2, 3, 4, 5, 6)
        val actual = mutableListOf(1, 2, 3, 4, 5, 6)
        assertEquals(actual, exchangeStartAndEnd(6, 0, expected))
    }

    @Test
    fun exchangeStartAndEnd_beginningIsZero() {
        val expected = mutableListOf(1, 2, 3, 4, 5, 6)
        val actual = mutableListOf(1, 2, 3, 4, 5, 6)
        assertEquals(actual, exchangeStartAndEnd(0, 6, expected))
    }

    @Test
    fun exchangeStartAndEnd_beginPlusEndNotEqualToArrayLength() {
        val array = mutableListOf(1, 2, 3, 4, 5, 6)
        assertThrows(IllegalArgumentException::class.java) {
            exchangeStartAndEnd(1, 3, array)
        }
    }

    @Test
    fun exchangeStartAndEnd_lengthOfBeginningEqualsToEnding() {
        val expected = mutableListOf(1, 2, 3, 4, 5, 6)
        val actual = mutableListOf(4, 5, 6, 1, 2, 3)
        assertEquals(actual, exchangeStartAndEnd(3, 3, expected))
    }

    @Test
    fun exchangeStartAndEnd_veryLongArray() {
        val expected = (0 until BIG_ARRAY_LENGTH).toMutableList()
        val actual = (1 until BIG_ARRAY_LENGTH).toMutableList()
        actual.add(0)
        assertEquals(actual, exchangeStartAndEnd(1, BIG_ARRAY_LENGTH - 1, expected))
    }

    @Test
    fun exchangeStartAndEnd_arrayIsOneElement() {
        val expected = mutableListOf(1)
        val actual = mutableListOf(1)
        assertEquals(actual, exchangeStartAndEnd(1, 0, expected))
    }

    @Test
    fun exchangeStartAndEnd_arrayIsEmpty() {
        val expected = mutableListOf<Int>()
        val actual = mutableListOf<Int>()
        assertEquals(actual, exchangeStartAndEnd(0, 0, expected))
    }
}

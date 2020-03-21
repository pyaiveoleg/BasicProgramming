package homeworks.homework1.task1

import org.junit.jupiter.api.Assertions.assertArrayEquals
import org.junit.jupiter.api.Assertions.assertThrows
import org.junit.jupiter.api.Test
import java.io.File

internal class MainTest {
    @Test
    fun exchangeStartAndEnd_usualCase() {
        val expected = intArrayOf(1, 2, 3, 4, 5, 6)
        val actual = intArrayOf(5, 6, 1, 2, 3, 4)
        assertArrayEquals(actual, exchangeStartAndEnd(4, 2, expected))
    }

    @Test
    fun exchangeStartAndEnd_endingIsZero() {
        val expected = intArrayOf(1, 2, 3, 4, 5, 6)
        val actual = intArrayOf(1, 2, 3, 4, 5, 6)
        assertArrayEquals(actual, exchangeStartAndEnd(6, 0, expected))
    }

    @Test
    fun exchangeStartAndEnd_beginningIsZero() {
        val expected = intArrayOf(1, 2, 3, 4, 5, 6)
        val actual = intArrayOf(1, 2, 3, 4, 5, 6)
        assertArrayEquals(actual, exchangeStartAndEnd(0, 6, expected))
    }

    @Test
    fun exchangeStartAndEnd_beginPlusEndNotEqualToArrayLength() {
        val array = intArrayOf(1, 2, 3, 4, 5, 6)
        assertThrows(IndexOutOfBoundsException::class.java) {
            exchangeStartAndEnd(1, 3, array)
        }
    }

    @Test
    fun exchangeStartAndEnd_lengthOfBeginningEqualsToEnding() {
        val expected = intArrayOf(1, 2, 3, 4, 5, 6)
        val actual = intArrayOf(4, 5, 6, 1, 2, 3)
        assertArrayEquals(actual, exchangeStartAndEnd(3, 3, expected))
    }

    @Test
    fun exchangeStartAndEnd_veryLongArray() {
        val input = File("./src/test/kotlin/homeworks/homework1/task1/bigArray.txt").readText()
        val expected = input.split(' ').map { it.toInt() }.toIntArray()
        val output = File("./src/test/kotlin/homeworks/homework1/task1/bigArrayResulting.txt").readText()
        val actual = output.split(' ').map { it.toInt() }.toIntArray()
        assertArrayEquals(actual, exchangeStartAndEnd(1, 99999, expected))
    }

    @Test
    fun exchangeStartAndEnd_arrayIsOneElement() {
        val expected = intArrayOf(1)
        val actual = intArrayOf(1)
        assertArrayEquals(actual, exchangeStartAndEnd(1, 0, expected))
    }

    @Test
    fun exchangeStartAndEnd_arrayIsEmpty() {
        val expected = intArrayOf()
        val actual = intArrayOf()
        assertArrayEquals(actual, exchangeStartAndEnd(0, 0, expected))
    }
}

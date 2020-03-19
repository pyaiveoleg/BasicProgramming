import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*
import java.lang.IllegalArgumentException

internal class MainTest {

    @Test
    fun reverse_OneItemInArray() {
        val expected = intArrayOf(1)
        val actual = intArrayOf(1)
        reverse(0, 0, expected)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun reverse_StartLessThanZero() {
        val array = intArrayOf(1, 2)
        assertThrows(ArrayIndexOutOfBoundsException::class.java) {
            reverse(-1, 1, array)
        }
    }

    @Test
    fun reverse_EndGreaterThanSize() {
        val array = intArrayOf(1, 2)
        assertThrows(ArrayIndexOutOfBoundsException::class.java) {
            reverse(1, 5, array)
        }
    }

    @Test
    fun reverse_StartGreaterThanEnd() {
        val expected = intArrayOf(1, 2, 3, 4)
        val actual = intArrayOf(1, 2, 3, 4)
        reverse(3, 1, expected)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun reverse_UsualCase() {
        val expected = intArrayOf(1, 2, 3, 4, 5, 6)
        val actual = intArrayOf(6, 5, 4, 3, 2, 1)
        reverse(0, 6, expected)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun exchangeStartAndEnd_UsualCase() {
        val expected = intArrayOf(1, 2, 3, 4, 5, 6)
        val actual = intArrayOf(5, 6, 1, 2, 3, 4)
        exchangeStartAndEnd(4, 2, actual)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun exchangeStartAndEnd_EndingIsZero() {
        val expected = intArrayOf(1, 2, 3, 4, 5, 6)
        val actual = intArrayOf(1, 2, 3, 4, 5, 6)
        exchangeStartAndEnd(6, 0, actual)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun exchangeStartAndEnd_BeginningIsZero() {
        val expected = intArrayOf(1, 2, 3, 4, 5, 6)
        val actual = intArrayOf(1, 2, 3, 4, 5, 6)
        exchangeStartAndEnd(0, 6, actual)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun exchangeStartAndEnd_BeginPlusEndNotEqualToArrayLength() {
        val expected = intArrayOf(1, 2, 3, 4, 5, 6)
        val actual = intArrayOf(2, 3, 4, 1, 5, 6)
        exchangeStartAndEnd(1, 3, actual)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun swap_Test() {
        val expected = intArrayOf(1, 2, 3, 4, 5, 6)
        val actual = intArrayOf(1, 4, 3, 2, 5, 6)
        swap(1, 3, actual)
        assertArrayEquals(expected, actual)
    }
}
import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

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
        val expected = intArrayOf(1, 2)
        val actual = intArrayOf(1, 2)
        reverse(-1, 1, expected)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun reverse_EndGreaterThanSize() {
        val expected = intArrayOf(1, 2)
        val actual = intArrayOf(1, 2)
        reverse(0, 10, expected)
        assertArrayEquals(expected, actual)
    }
}
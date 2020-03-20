import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class MainTest {
    @Test
    fun removeRepeatingElements_allAreDistinct() {
        val expected = intArrayOf(1, 2, 3, 4, 5, 6).toTypedArray()
        val actual = removeRepeatingElements(intArrayOf(1, 2, 3, 4, 5, 6).toTypedArray())
        assertArrayEquals(expected, actual)
    }

    @Test
    fun removeRepeatingElements_allAreEqual() {
        val expected = intArrayOf(1).toTypedArray()
        val actual = removeRepeatingElements(intArrayOf(1, 1, 1, 1, 1).toTypedArray())
        assertArrayEquals(expected, actual)
    }

    @Test
    fun removeRepeatingElements_someAreEqual() {
        val expected = intArrayOf(1, 5, 2, 8, 0).toTypedArray()
        val actual = removeRepeatingElements(intArrayOf(1, 5, 5, 2, 2, 8, 8, 8, 0).toTypedArray())
        assertArrayEquals(expected, actual)
    }

    @Test
    fun removeRepeatingElements_equalAreNotInRow() {
        val expected = intArrayOf(1, 2, 3).toTypedArray()
        val actual = removeRepeatingElements(intArrayOf(1, 2, 1, 3, 1).toTypedArray())
        assertArrayEquals(expected, actual)
    }

    @Test
    fun removeRepeatingElements_allEqualAreNotInRow() {
        val expected = intArrayOf(2, 1).toTypedArray()
        val actual = removeRepeatingElements(intArrayOf(2, 1, 2, 1, 2, 1, 1, 2).toTypedArray())
        assertArrayEquals(expected, actual)
    }
}
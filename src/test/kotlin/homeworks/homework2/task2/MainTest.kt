package homeworks.homework2.task2

import org.junit.jupiter.api.Assertions.assertArrayEquals
import org.junit.jupiter.api.Test
import java.io.File

internal class MainTest {
    private val bigArrayLength = 100000

    @Test
    fun removeRepeatingElements_allAreDistinct() {
        val expected = arrayOf<Any>(1, 2, 3, 4, 5, 6)
        val actual = removeRepeatingElements(arrayOf(1, 2, 3, 4, 5, 6))
        assertArrayEquals(expected, actual)
    }

    @Test
    fun removeRepeatingElements_allAreEqual() {
        val expected = arrayOf<Any>(1)
        val actual = removeRepeatingElements(arrayOf(1, 1, 1, 1, 1))
        assertArrayEquals(expected, actual)
    }

    @Test
    fun removeRepeatingElements_someAreEqual() {
        val expected = arrayOf<Any>(1, 5, 2, 8, 0)
        val actual = removeRepeatingElements(arrayOf(1, 5, 5, 2, 2, 8, 8, 8, 0))
        assertArrayEquals(expected, actual)
    }

    @Test
    fun removeRepeatingElements_equalAreNotInRow() {
        val expected = arrayOf<Any>(2, 3, 1)
        val actual = removeRepeatingElements(arrayOf(1, 2, 1, 3, 1))
        assertArrayEquals(expected, actual)
    }

    @Test
    fun removeRepeatingElements_allEqualAreNotInRow() {
        val expected = arrayOf<Any>(1, 2)
        val actual = removeRepeatingElements(arrayOf(2, 1, 2, 1, 2, 1, 1, 2))
        assertArrayEquals(expected, actual)
    }

    @Test
    fun removeRepeatingElements_emptyArray() {
        val expected = arrayOf<Any>()
        val actual = removeRepeatingElements(arrayOf())
        assertArrayEquals(expected, actual)
    }

    @Test
    fun removeRepeatingElements_veryBigArray() {
        val expected = (0 until bigArrayLength).toMutableList()
        expected.add(0)
        val actual = (1 until bigArrayLength).toMutableList()
        actual.add(0)
        assertArrayEquals(actual.toTypedArray(), removeRepeatingElements(expected.toTypedArray()))
    }
}

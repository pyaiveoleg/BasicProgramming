package homeworks.homework2.task1

import org.junit.jupiter.api.Assertions.assertArrayEquals
import org.junit.jupiter.api.Test
import java.io.File

internal class MainTest {
    @Test
    fun removeRepeatingElements_allAreDistinct() {
        val expected = intArrayOf(1, 2, 3, 4, 5, 6)
        val actual = removeRepeatingElements(intArrayOf(1, 2, 3, 4, 5, 6))
        assertArrayEquals(expected, actual)
    }

    @Test
    fun removeRepeatingElements_allAreEqual() {
        val expected = intArrayOf(1)
        val actual = removeRepeatingElements(intArrayOf(1, 1, 1, 1, 1))
        assertArrayEquals(expected, actual)
    }

    @Test
    fun removeRepeatingElements_someAreEqual() {
        val expected = intArrayOf(1, 5, 2, 8, 0)
        val actual = removeRepeatingElements(intArrayOf(1, 5, 5, 2, 2, 8, 8, 8, 0))
        assertArrayEquals(expected, actual)
    }

    @Test
    fun removeRepeatingElements_equalAreNotInRow() {
        val expected = intArrayOf(2, 3, 1)
        val actual = removeRepeatingElements(intArrayOf(1, 2, 1, 3, 1))
        assertArrayEquals(expected, actual)
    }

    @Test
    fun removeRepeatingElements_allEqualAreNotInRow() {
        val expected = intArrayOf(1, 2)
        val actual = removeRepeatingElements(intArrayOf(2, 1, 2, 1, 2, 1, 1, 2))
        assertArrayEquals(expected, actual)
    }

    @Test
    fun removeRepeatingElements_emptyArray() {
        val expected = intArrayOf()
        val actual = removeRepeatingElements(intArrayOf())
        assertArrayEquals(expected, actual)
    }

    @Test
    fun removeRepeatingElements_veryBigArray() {
        val input = File("./src/test/resources/homeworks/homework2/task1/bigArray.txt").readText()
        val output = File("./src/test/resources/homeworks/homework2/task1/bigArrayResulting.txt").readText()
        val expected = output.split(' ').map { it.toInt() }.toIntArray()
        val actual = removeRepeatingElements(input.split(' ').map { it.toInt() }.toIntArray())
        assertArrayEquals(expected, actual)
    }
}

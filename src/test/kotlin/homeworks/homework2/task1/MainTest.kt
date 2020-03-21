package homeworks.homework2.task1

import org.junit.jupiter.api.Assertions.assertArrayEquals
import org.junit.jupiter.api.Test
import java.io.File

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

    @Test
    fun removeRepeatingElements_emptyArray() {
        val expected = intArrayOf().toTypedArray()
        val actual = removeRepeatingElements(intArrayOf().toTypedArray())
        assertArrayEquals(expected, actual)
    }

    @Test
    fun removeRepeatingElements_veryBigArray() {
        val input = File("./src/test/resources/homeworks/homework2/task1/bigArray.txt").readText()
        val output = File("./src/test/resources/homeworks/homework2/task1/bigArrayResulting.txt").readText()
        val expected = output.split(' ').map { it.toInt() }.toTypedArray()
        val actual = removeRepeatingElements(input.split(' ').map { it.toInt() }.toTypedArray())
        assertArrayEquals(expected, actual)
    }
}

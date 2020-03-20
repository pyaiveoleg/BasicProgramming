import org.junit.jupiter.api.Test
import org.junit.jupiter.api.Assertions.*

internal class MainTest {
    @Test
    fun reverse_oneItemInArray() {
        val expected = intArrayOf(1)
        val actual = intArrayOf(1)
        reverse(0, 0, expected)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun reverse_startLessThanZero() {
        val array = intArrayOf(1, 2)
        assertThrows(ArrayIndexOutOfBoundsException::class.java) {
            reverse(-1, 1, array)
        }
    }

    @Test
    fun reverse_endGreaterThanSize() {
        val array = intArrayOf(1, 2)
        assertThrows(ArrayIndexOutOfBoundsException::class.java) {
            reverse(1, 5, array)
        }
    }

    @Test
    fun reverse_startGreaterThanEnd() {
        val expected = intArrayOf(1, 2, 3, 4)
        val actual = intArrayOf(1, 2, 3, 4)
        reverse(3, 1, expected)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun reverse_usualCase() {
        val expected = intArrayOf(1, 2, 3, 4, 5, 6)
        val actual = intArrayOf(6, 5, 4, 3, 2, 1)
        reverse(0, 6, expected)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun exchangeStartAndEnd_usualCase() {
        val expected = intArrayOf(1, 2, 3, 4, 5, 6)
        val actual = intArrayOf(5, 6, 1, 2, 3, 4)
        exchangeStartAndEnd(4, 2, actual)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun exchangeStartAndEnd_endingIsZero() {
        val expected = intArrayOf(1, 2, 3, 4, 5, 6)
        val actual = intArrayOf(1, 2, 3, 4, 5, 6)
        exchangeStartAndEnd(6, 0, actual)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun exchangeStartAndEnd_beginningIsZero() {
        val expected = intArrayOf(1, 2, 3, 4, 5, 6)
        val actual = intArrayOf(1, 2, 3, 4, 5, 6)
        exchangeStartAndEnd(0, 6, actual)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun exchangeStartAndEnd_beginPlusEndNotEqualToArrayLength() {
        val expected = intArrayOf(1, 2, 3, 4, 5, 6)
        val actual = intArrayOf(2, 3, 4, 1, 5, 6)
        exchangeStartAndEnd(1, 3, actual)
        assertArrayEquals(expected, actual)
    }

    @Test
    fun swap_test() {
        val expected = intArrayOf(1, 2, 3, 4, 5, 6)
        val actual = intArrayOf(1, 4, 3, 2, 5, 6)
        swap(1, 3, actual)
        assertArrayEquals(expected, actual)
    }
}
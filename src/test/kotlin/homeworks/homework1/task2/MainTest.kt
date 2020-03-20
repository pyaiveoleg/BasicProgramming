package homeworks.homework1.task2

import org.junit.jupiter.api.Assertions.assertEquals
import org.junit.jupiter.api.Assertions.assertThrows
import org.junit.jupiter.api.Test

internal class MainTest {
    @Test
    fun recursiveFactorial_numberIsZero() {
        assertEquals(1, recursiveFactorial(0))
    }

    @Test
    fun recursiveFactorial_numberIsNegative() {
        assertThrows(IllegalArgumentException::class.java) {
            recursiveFactorial(-4)
        }
    }

    @Test
    fun recursiveFactorial_numberIsPositive() {
        assertEquals(24, recursiveFactorial(4))
    }

    @Test
    fun recursiveFactorial_numberIsBigPositive() {
        assertEquals(39916800, recursiveFactorial(11))
    }

    @Test
    fun iterativeFactorial_numberIsZero() {
        assertEquals(1, recursiveFactorial(0))
    }

    @Test
    fun iterativeFactorial_numberIsPositive() {
        assertEquals(24, recursiveFactorial(4))
    }

    @Test
    fun iterativeFactorial_numberIsNegative() {
        assertThrows(IllegalArgumentException::class.java) {
            iterativeFactorial(-4)
        }
    }

    @Test
    fun iterativeFactorial_numberIsBigPositive() {
        assertEquals(39916800, recursiveFactorial(11))
    }
}
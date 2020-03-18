import org.junit.jupiter.api.Assertions.assertEquals
import org.junit.jupiter.api.Assertions.assertThrows
import org.junit.jupiter.api.Test
import java.lang.IllegalArgumentException

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
}
import org.junit.jupiter.api.Assertions.assertFalse
import org.junit.jupiter.api.Assertions.assertTrue
import org.junit.jupiter.api.Test

internal class MainTest {
    @Test
    fun checkPalindrome_isPalindrome() {
        assertTrue(checkPalindrome("12321"))
    }

    @Test
    fun checkPalindrome_isNotPalindrome() {
        assertFalse(checkPalindrome("1021"))
    }

    @Test
    fun checkPalindrome_isEmpty() {
        assertTrue(checkPalindrome(""))
    }

    @Test
    fun checkPalindrome_oneSymbol() {
        assertTrue(checkPalindrome("a"))
    }

    @Test
    fun checkPalindrome_containsOfEqualSymbols() {
        assertTrue(checkPalindrome("aaaaa"))
    }

    @Test
    fun checkPalindrome_twoEqualSymbolsInTheMiddle() {
        assertTrue(checkPalindrome("2332"))
    }

    @Test
    fun checkPalindrome_gapsInTheEnd() {
        assertFalse(checkPalindrome("2332  "))
    }

    @Test
    fun checkPalindrome_gapsInTheMiddleAndPartsArePalindromes() {
        assertFalse(checkPalindrome("aba cdc"))
    }
}
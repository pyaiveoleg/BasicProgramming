import org.junit.jupiter.api.Assertions.*
import org.junit.jupiter.api.Test

internal class MainTest
{
    @Test
    fun countInclusions_stringsAreEqual()
    {
        val inputString = "Test_string"
        val pattern = "Test_string"
        assertEquals(1, countInclusions(inputString, pattern))
    }

    @Test
    fun countInclusions_stringsContainGaps()
    {
        val inputString = "Test string with gaps"
        val pattern = "Test string with gaps"
        assertEquals(1, countInclusions(inputString, pattern))
    }

    @Test
    fun countInclusions_gapOnEndOfPattern()
    {
        val inputString = "Test"
        val pattern = "Test "
        assertEquals(0, countInclusions(inputString, pattern))
    }

    @Test
    fun countInclusions_inputStringContainsFromSeveralPatterns()
    {
        val inputString = "TestTest"
        val pattern = "Test"
        assertEquals(2, countInclusions(inputString, pattern))
    }

    @Test
    fun countInclusions_stringsConsistOfOneLetter()
    {
        val inputString = "aaaa"
        val pattern = "aaa"
        assertEquals(2, countInclusions(inputString, pattern))
    }

    @Test
    fun countInclusions_stringsConsistOfOneDigit()
    {
        val inputString = "1111"
        val pattern = "1"
        assertEquals(4, countInclusions(inputString, pattern))
    }

    @Test
    fun countInclusions_uppercaseAndLowcaseInStrings()
    {
        val inputString = "aTeSt"
        val pattern = "AtEst"
        assertEquals(0, countInclusions(inputString, pattern))
    }

    @Test
    fun countInclusions_inclusionIsOnTheEnd()
    {
        val inputString = "stringS"
        val pattern = "ingS"
        assertEquals(1, countInclusions(inputString, pattern))
    }
}
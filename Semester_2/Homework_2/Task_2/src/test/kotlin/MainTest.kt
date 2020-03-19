import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class MainTest
{
    @Test
    fun countQuantityOfSymbolsToDelete_stringIsOneSymbol()
    {
        assertEquals(0, countQuantityOfSymbolsToDelete("a"))
    }

    @Test
    fun countQuantityOfSymbolsToDelete_stringContainsOneTypeOfSymbols()
    {
        assertEquals(3, countQuantityOfSymbolsToDelete("xxxxx"))
    }

    @Test
    fun countQuantityOfSymbolsToDelete_lengthIsLessThanThree()
    {
        assertEquals(0, countQuantityOfSymbolsToDelete("xx"))
    }

    @Test
    fun countQuantityOfSymbolsToDelete_severalInclusionsOfXXX()
    {
        assertEquals(2, countQuantityOfSymbolsToDelete("abxxxcdxxxba"))
    }

    @Test
    fun countQuantityOfSymbolsToDelete_oneInclusionOfXXX()
    {
        assertEquals(1, countQuantityOfSymbolsToDelete("axxxaa"))
    }

    @Test
    fun countQuantityOfSymbolsToDelete_xInUpperCase()
    {
        assertEquals(0, countQuantityOfSymbolsToDelete("XxXxxX"))
    }

    @Test
    fun countQuantityOfSymbolsToDelete_emptyString()
    {
        assertEquals(0, countQuantityOfSymbolsToDelete(""))
    }

    @Test
    fun countQuantityOfSymbolsToDelete_stringIsXXX()
    {
        assertEquals(1, countQuantityOfSymbolsToDelete("xxx"))
    }
}
import org.junit.jupiter.api.Assertions.assertEquals
import org.junit.jupiter.api.Assertions.assertThrows
import org.junit.jupiter.api.Test
import java.io.File
import java.io.InvalidObjectException

internal class MainTest {
    @Test
    fun countNotEmptyStrings_FileDoesNotExists() {
        val input = File("./src/test/resources/FileDoesNotExists.txt")
        assertThrows(InvalidObjectException::class.java) {
            countNotEmptyStrings(input)
        }
    }

    @Test
    fun countNotEmptyStrings_FileIsEmpty() {
        val input = File("./src/test/resources/FileIsEmpty.txt")
        assertEquals(0, countNotEmptyStrings(input))
    }

    @Test
    fun countNotEmptyStrings_OneLine() {
        val input = File("./src/test/resources/OneLine.txt")
        assertEquals(1, countNotEmptyStrings(input))
    }

    @Test
    fun countNotEmptyStrings_OneLineWithEnter() {
        val input = File("./src/test/resources/OneLineWithEnter.txt")
        assertEquals(1, countNotEmptyStrings(input))
    }

    @Test
    fun countNotEmptyStrings_EmptyLinesAreOnlyTabs() {
        val input = File("./src/test/resources/EmptyLinesAreOnlyTabs.txt")
        assertEquals(3, countNotEmptyStrings(input))
    }

    @Test
    fun countNotEmptyStrings_EmptyLinesAreOnlyGaps() {
        val input = File("./src/test/resources/EmptyLinesAreOnlyGaps.txt")
        assertEquals(3, countNotEmptyStrings(input))
    }

    @Test
    fun countNotEmptyStrings_OneNotEmptyLine() {
        val input = File("./src/test/resources/OneNotEmptyLine.txt")
        assertEquals(1, countNotEmptyStrings(input))
    }

    @Test
    fun countNotEmptyStrings_TwoNotEmptyLines() {
        val input = File("./src/test/resources/TwoNotEmptyLines.txt")
        assertEquals(2, countNotEmptyStrings(input))
    }

    @Test
    fun countNotEmptyStrings_AllLinesAreNotEmpty() {
        val input = File("./src/test/resources/AllLinesAreNotEmpty.txt")
        assertEquals(7, countNotEmptyStrings(input))
    }
}

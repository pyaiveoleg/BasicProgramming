package homeworks.homework7.task2

import org.junit.jupiter.api.Assertions.assertFalse
import org.junit.jupiter.api.Test

internal class TIcTacToeTest {
    private val model = TicTacToe
    private val x = model.CROSS
    private val o = model.ZERO

    @Test
    fun winning_boardIsEmpty() {
        val board = mutableListOf(
            0, 1, 2,
            3, 4, 5,
            6, 7, 8
        )
        assertFalse(model.winning(board, x))
    }

    @Test
    fun winning_upperRow() {
        val board = mutableListOf(
            x, x, x,
            3, 4, 5,
            6, 7, 8
        )
        assert(model.winning(board, x))
    }

    @Test
    fun winning_middleRow() {
        val board = mutableListOf(
            0, 1, 2,
            x, x, x,
            6, 7, 8
        )
        assert(model.winning(board, x))
    }

    @Test
    fun winning_downRow() {
        val board = mutableListOf(
            0, 1, 2,
            3, 4, 5,
            x, x, x
        )
        assert(model.winning(board, x))
    }

    @Test
    fun winning_mainDiagonal() {
        val board = mutableListOf(
            o, 1, 2,
            3, o, 5,
            6, 7, o
        )
        assert(model.winning(board, o))
    }

    @Test
    fun winning_sideDiagonal() {
        val board = mutableListOf(
            0, 1, o,
            3, o, 5,
            o, 7, 8
        )
        assert(model.winning(board, o))
    }

    @Test
    fun winning_leftRow() {
        val board = mutableListOf(
            o, 1, 2,
            o, 4, 5,
            o, 7, 8
        )
        assert(model.winning(board, o))
    }

    @Test
    fun winning_middleVerticalRow() {
        val board = mutableListOf(
            0, o, 2,
            3, o, 5,
            6, o, 8
        )
        assert(model.winning(board, o))
    }

    @Test
    fun winning_rightRow() {
        val board = mutableListOf(
            0, 1, x,
            3, 4, x,
            6, 7, x
        )
        assert(model.winning(board, x))
    }

    @Test
    fun winning_anotherPlayer() {
        val board = mutableListOf(
            0, 1, x,
            3, 4, x,
            6, 7, x
        )
        assertFalse(model.winning(board, o))
    }

    @Test
    fun winning_noCrossWin() {
        val board = mutableListOf(
            0, 1, x,
            3, 4, x,
            6, 7, o
        )
        assertFalse(model.winning(board, x))
    }

    @Test
    fun winning_noZeroWin() {
        val board = mutableListOf(
            0, 1, x,
            3, 4, x,
            6, 7, o
        )
        assertFalse(model.winning(board, o))
    }
}

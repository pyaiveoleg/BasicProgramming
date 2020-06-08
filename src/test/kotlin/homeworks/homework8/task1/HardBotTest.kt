package homeworks.homework7.task2

import org.junit.jupiter.api.Assertions.assertArrayEquals
import org.junit.jupiter.api.Test

internal class HardBotTest {
    private val model = TicTacToe
    val x = model.CROSS
    val o = model.ZERO

    @Test
    fun makeMove_boardIsEmpty() {
        val board = mutableListOf(
            0, 1, 2,
            3, 4, 5,
            6, 7, 8
        )
        val currentMove = "x"
        val bestMove = intArrayOf(0, 0)
        assertArrayEquals(bestMove, HardBot.makeMove(board, currentMove))
    }

    @Test
    fun makeMove_oneCrossInCenter() {
        val board = mutableListOf(
            0, 1, 2,
            3, x, 5,
            6, 7, 8
        )
        val currentMove = "o"
        val bestMove = intArrayOf(0, 0)
        assertArrayEquals(bestMove, HardBot.makeMove(board, currentMove))
    }

    @Test
    fun makeMove_oneCrossInLeftUpperCorner() {
        val board = mutableListOf(
            x, 1, 2,
            3, 4, 5,
            6, 7, 8
        )
        val currentMove = "o"
        val bestMove = intArrayOf(1, 1)
        assertArrayEquals(bestMove, HardBot.makeMove(board, currentMove))
    }

    @Test
    fun makeMove_twoMovesCompleted() {
        val board = mutableListOf(
            0, 1, 2,
            3, 4, o,
            6, x, 8
        )
        val currentMove = "x"
        val bestMove = intArrayOf(1, 1)
        assertArrayEquals(bestMove, HardBot.makeMove(board, currentMove))
    }

    @Test
    fun makeMove_canWin() {
        val board = mutableListOf(
            0, 1, o,
            3, 4, o,
            x, x, 8
        )
        val currentMove = "x"
        val bestMove = intArrayOf(2, 2)
        assertArrayEquals(bestMove, HardBot.makeMove(board, currentMove))
    }

    @Test
    fun makeMove_opponentCanWinInOneMove() {
        val board = mutableListOf(
            0, 1, o,
            x, 4, o,
            6, x, 8
        )
        val currentMove = "x"
        val bestMove = intArrayOf(2, 2)
        assertArrayEquals(bestMove, HardBot.makeMove(board, currentMove))
    }

    @Test
    fun makeMove_oneFreePoint() {
        val board = mutableListOf(
            o, x, 2,
            x, x, o,
            o, o, x
        )
        val currentMove = "o"
        val bestMove = intArrayOf(2, 0)
        assertArrayEquals(bestMove, HardBot.makeMove(board, currentMove))
    }
}

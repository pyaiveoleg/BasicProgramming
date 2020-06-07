package homeworks.homework7.task2

import javafx.beans.property.SimpleStringProperty

object HardBot {
    private const val hugeScore = 20000
    private const val scoreStep = 20
    private const val boardSide = 3
    private const val codeOfX = 2
    private const val codeOfO = 1
    private var human = 0
    private var ai = 0

    fun makeMove(board: MutableList<Int>, currentMove: SimpleStringProperty): IntArray {
        human = if (currentMove.value == "x") {
            codeOfX
        } else {
            codeOfO
        }
        ai = if (currentMove.value == "x") {
            codeOfO
        } else {
            codeOfX
        }

        val pointToMove = minimax(board, ai)
        val xMove = pointToMove.index % boardSide
        val yMove: Int = pointToMove.index / boardSide
        return intArrayOf(xMove, yMove)
    }

    data class Move(var index: Int = 0, var score: Int = 0)

    private fun estimateMoves(availablePoints: MutableList<Int>, newBoard: MutableList<Int>, player: Int): MutableList<Move> {
        val moves = mutableListOf<Move>()
        for (i in 0 until availablePoints.size) {
            val move = Move(newBoard[availablePoints[i]], 0)
            newBoard[availablePoints[i]] = if (player == 1) {
                TicTacToe.CROSS
            } else {
                TicTacToe.ZERO
            }

            if (player == ai) {
                val result = minimax(newBoard, human)
                move.score = result.score
            } else {
                val result = minimax(newBoard, ai)
                move.score = result.score
            }

            newBoard[availablePoints[i]] = move.index
            moves.add(move)
        }
        return moves
    }

    private fun calculateForAi(moves: MutableList<Move>): Int {
        var bestMove = -1
        var bestScore = -hugeScore
        for (i in 0 until moves.size) {
            if (moves[i].score > bestScore) {
                bestScore = moves[i].score
                bestMove = i
            }
        }
        return bestMove
    }

    private fun calculateForHuman(moves: MutableList<Move>): Int {
        var bestMove = -1
        var bestScore = hugeScore
        for (i in 0 until moves.size) {
            if (moves[i].score < bestScore) {
                bestScore = moves[i].score
                bestMove = i
            }
        }
        return bestMove
    }

    private fun minimax(newBoard: MutableList<Int>, player: Int): Move {
        val availablePoints = mutableListOf<Int>()
        for (cell in newBoard) {
            if (cell in 0 until boardSide * boardSide) {
                availablePoints.add(cell)
            }
        }

        var terminalState: Move? = null
        if (human == codeOfO && TicTacToe.winning(newBoard, TicTacToe.CROSS) ||
            human == codeOfX && TicTacToe.winning(newBoard, TicTacToe.ZERO)
        ) {
            terminalState = Move(-1, -scoreStep)
        }
        if (ai == codeOfO && TicTacToe.winning(newBoard, TicTacToe.CROSS) ||
            ai == codeOfX && TicTacToe.winning(newBoard, TicTacToe.ZERO)
        ) {
            terminalState = Move(-1, scoreStep)
        }
        if (availablePoints.size == 0) {
            terminalState = Move(-1, 0)
        }

        if (terminalState != null) {
            return terminalState
        }

        val moves = estimateMoves(availablePoints, newBoard, player)

        val bestMove = if (player == ai) {
            calculateForAi(moves)
        } else {
            calculateForHuman(moves)
        }
        return moves[bestMove]
    }
}

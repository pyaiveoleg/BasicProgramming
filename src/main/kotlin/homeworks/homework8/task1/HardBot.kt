package homeworks.homework7.task2

import javafx.beans.property.SimpleStringProperty

class HardBot {
    private var human = 0
    private var ai = 0

    fun makeMove(board: MutableList<Int>, currentMove: SimpleStringProperty): Array<Int> {
        human = if (currentMove.value == "x") {
            2
        } else {
            1
        }
        ai = if (currentMove.value == "x") {
            1
        } else {
            2
        }

        val pointToMove = minimax(board, ai)
        val xMove = pointToMove.index % 3
        val yMove: Int = pointToMove.index / 3
        return arrayOf(xMove, yMove)
    }

    class Move(newIndex: Int = 0, newScore: Int = 0) {
        var index: Int = newIndex
        var score: Int = newScore
    }

    private fun minimax(newBoard: MutableList<Int>, player: Int): Move {
        val availablePoints = mutableListOf<Int>()
        for (cell in newBoard) {
            if (cell in 0 until 9) {
                availablePoints.add(cell)
            }
        }
        if (human == 1 && TicTacToe.winning(newBoard, TicTacToe.CROSS) ||
            human == 2 && TicTacToe.winning(newBoard, TicTacToe.ZERO)
        ) {
            return Move(-1, -20)
        }
        if (ai == 1 && TicTacToe.winning(newBoard, TicTacToe.CROSS) ||
            ai == 2 && TicTacToe.winning(newBoard, TicTacToe.ZERO)
        ) {
            return Move(-1, 20)
        }
        if (availablePoints.size == 0) {
            return Move(-1, 0)
        }

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

        var bestMove = 0
        if (player == ai) {
            var bestScore = -20000
            for (i in 0 until moves.size) {
                if (moves[i].score > bestScore) {
                    bestScore = moves[i].score
                    bestMove = i
                }
            }
        } else {
            var bestScore = 20000
            for (i in 0 until moves.size) {
                if (moves[i].score < bestScore) {
                    bestScore = moves[i].score
                    bestMove = i
                }
            }
        }
        return moves[bestMove]
    }
}

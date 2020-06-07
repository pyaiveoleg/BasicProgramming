package homeworks.homework7.task2

import javafx.beans.property.SimpleStringProperty
import tornadofx.find

object TicTacToe {
    private const val leftUpperCorner = 0
    private const val upperMiddle = 1
    private const val rightUpperCorner = 2
    private const val leftMiddle = 3
    private const val middle = 4
    private const val rightMiddle = 5
    private const val leftDownCorner = 6
    private const val downMiddle = 7
    private const val rightDownCorner = 8

    const val CROSS = 10
    const val ZERO = -10

    var board = (0..8).toMutableList()
    val table = arrayOf(
        listOf(SimpleStringProperty(""), SimpleStringProperty(""), SimpleStringProperty("")),
        listOf(SimpleStringProperty(""), SimpleStringProperty(""), SimpleStringProperty("")),
        listOf(SimpleStringProperty(""), SimpleStringProperty(""), SimpleStringProperty(""))
    )
    val queueWithBoard = Queue()
    val currentMove = SimpleStringProperty("x")
    var numberOfPlayer = -1
    val controller = find(MainController::class)
    var isOpponentMoved = false

    fun changeMove() {
        if (currentMove.value == "x") {
            currentMove.value = "o"
        } else {
            currentMove.value = "x"
        }
    }

    private fun isDiagonalRow(board: MutableList<Int>, player: Int): Boolean {
        return (board[leftUpperCorner] == player && board[middle] == player && board[rightDownCorner] == player) ||
               (board[rightUpperCorner] == player && board[middle] == player && board[leftDownCorner] == player)
    }

    private fun isHorizontalRow(board: MutableList<Int>, player: Int): Boolean {
        return (board[leftUpperCorner] == player && board[upperMiddle] == player && board[rightUpperCorner] == player) ||
                (board[leftMiddle] == player && board[middle] == player && board[rightMiddle] == player) ||
                (board[leftDownCorner] == player && board[downMiddle] == player && board[rightDownCorner] == player)
    }

    private fun isVerticalRow(board: MutableList<Int>, player: Int): Boolean {
        return (board[leftUpperCorner] == player && board[leftMiddle] == player && board[leftDownCorner] == player) ||
               (board[upperMiddle] == player && board[middle] == player && board[downMiddle] == player) ||
               (board[rightUpperCorner] == player && board[rightMiddle] == player && board[rightDownCorner] == player)
    }

    fun winning(board: MutableList<Int>, player: Int): Boolean {
        return isDiagonalRow(board, player) || isVerticalRow(board, player) || isHorizontalRow(board, player)
    }
}

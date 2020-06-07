package homeworks.homework7.task2

import javafx.beans.property.SimpleStringProperty
import tornadofx.find

object TicTacToe {
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

    fun winning(board: MutableList<Int>, player: Int): Boolean {
        return (board[0] == player && board[1] == player && board[2] == player) ||
                (board[3] == player && board[4] == player && board[5] == player) ||
                (board[6] == player && board[7] == player && board[8] == player) ||
                (board[0] == player && board[3] == player && board[6] == player) ||
                (board[1] == player && board[4] == player && board[7] == player) ||
                (board[2] == player && board[5] == player && board[8] == player) ||
                (board[0] == player && board[4] == player && board[8] == player) ||
                (board[2] == player && board[4] == player && board[6] == player)
    }
}

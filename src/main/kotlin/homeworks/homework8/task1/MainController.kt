package homeworks.homework7.task2

import io.ktor.util.KtorExperimentalAPI
import javafx.beans.property.SimpleStringProperty
import tornadofx.Controller

class MainController : Controller() {
    val model = TicTacToe
    private var winner: Int? = null
    var winMessage = SimpleStringProperty()
    private val hardBot = HardBot()
    private val easyBot = EasyBot()
    private var humanSide: Int? = null
    private var mode: String = ""
    private val onlineMode = OnlineMode()

    @KtorExperimentalAPI
    fun changeMode(newMode: String) {
        winner = null
        if (newMode.isNotEmpty()) {
            mode = newMode
        }
        if (newMode == "Online") {
            onlineMode.start()
        }
        model.board = (0..8).toMutableList()
        model.currentMove.value = "x"
    }

    fun checkWinner() {
        winner = null
        if (model.winning(model.board, model.CROSS)) {
            winner = 1
        } else if (model.winning(model.board, model.ZERO)) {
            winner = 2
        }

        val availablePoints = mutableListOf<Int>()
        for (cell in model.board) {
            if (cell in 0 until 9) {
                availablePoints.add(cell)
            }
        }
        if (availablePoints.size == 0) {
            winner = 0
        }

        if (winner != null) {
            if (winner != 0) {
                winMessage.value = "Player $winner won!"
            } else {
                winMessage.value = "Draw!"
            }
            find(MainView::class).replaceWith<EndView>()
        }
    }

    fun clearTable() {
        for (i in 0..2) {
            for (j in 0..2) {
                model.table[i][j].value = ""
            }
        }
    }

    private fun move(x: Int, y: Int) {
        model.table[x][y].value = model.currentMove.value
        model.board[3 * y + x] = if (model.currentMove.value == "x") {
            model.CROSS
        } else {
            model.ZERO
        }
        model.changeMove()
        checkWinner()
    }

    fun changeSide(newSide: Int?) {
        if (newSide == 1 || newSide == 2) {
            humanSide = newSide
        }
        if (humanSide == 2) {
            val coordinates = if (mode == "Hard") {
                hardBot.makeMove(model.board, model.currentMove)
            } else {
                easyBot.makeMove(model.board)
            }
            val xMove = coordinates[0]
            val yMove = coordinates[1]
            move(xMove, yMove)
        }
    }

    @KtorExperimentalAPI
    fun play(x: Int, y: Int) {
        if (model.table[x][y].value.isNotEmpty() || (mode == "Online" && !model.isOpponentMoved)) {
            return
        }
        move(x, y)
        println("1")
        if (mode == "Online") {
            model.queueWithBoard.set(model.board.toString())
            model.changeMove()
            model.isOpponentMoved = false
        }

        if ((mode == "Hard" || mode == "Easy") && winner == null) {
            val coordinates = if (mode == "Hard") {
                hardBot.makeMove(model.board, model.currentMove)
            } else {
                easyBot.makeMove(model.board)
            }
            val xMove = coordinates[0]
            val yMove = coordinates[1]
            move(xMove, yMove)
        }
    }
}

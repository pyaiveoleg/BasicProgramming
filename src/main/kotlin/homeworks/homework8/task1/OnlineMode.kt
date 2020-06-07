package homeworks.homework7.task2

import io.ktor.client.HttpClient
import io.ktor.client.features.websocket.WebSockets
import io.ktor.client.features.websocket.ws
import io.ktor.http.HttpMethod
import io.ktor.http.cio.websocket.Frame
import io.ktor.http.cio.websocket.readText
import io.ktor.util.KtorExperimentalAPI
import javafx.application.Platform
import kotlinx.coroutines.runBlocking

class OnlineMode : Thread() {
    private val model = TicTacToe
    @KtorExperimentalAPI
    override fun run() {
        val client = HttpClient {
            install(WebSockets)
        }

        runBlocking {
            print("start")
            client.ws(
                method = HttpMethod.Get,
                host = "127.0.0.1",
                port = 8080, path = "/"
            ) {
                when (val frame = incoming.receive()) {
                    is Frame.Text -> {
                        model.numberOfPlayer = frame.readText().toInt()
                        Platform.runLater(define)
                    }
                }

                while (true) {
                    if (model.numberOfPlayer == 1) {
                        val data = model.queueWithBoard.get()
                        send(Frame.Text(data.toString()))
                    }

                    when (val frame = incoming.receive()) {
                        is Frame.Text -> {
                            val received = (frame.readText().split("[")[1]).split("]")[0].split(",").map { it.trim() }
                            model.board = received.map { it.toInt() }.toMutableList()
                            Platform.runLater(updater)
                        }
                    }

                    if (model.numberOfPlayer == 2) {
                        val data = model.queueWithBoard.get()
                        send(Frame.Text(data.toString()))
                    }
                }
            }
        }
    }

    private val define = Runnable {
        if (model.numberOfPlayer == 2) {
            model.currentMove.value = "o"
        }
        if (model.numberOfPlayer == 1) {
            model.isOpponentMoved = true
        }
    }

    private val updater = Runnable {
        for (y1 in 0..2) {
            for (x1 in 0..2) {
                if (model.board[3 * y1 + x1] == model.ZERO) {
                    model.table[x1][y1].value = "o"
                }
                if (model.board[3 * y1 + x1] == model.CROSS) {
                    model.table[x1][y1].value = "x"
                }
            }
        }
        model.isOpponentMoved = true
        model.controller.checkWinner()
    }
}

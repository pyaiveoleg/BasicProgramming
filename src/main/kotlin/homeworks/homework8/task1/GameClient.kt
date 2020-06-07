package homeworks.homework7.task2

import io.ktor.application.Application
import io.ktor.application.call
import io.ktor.application.install
import io.ktor.http.cio.websocket.DefaultWebSocketSession
import io.ktor.http.cio.websocket.Frame
import io.ktor.http.cio.websocket.readText
import io.ktor.response.respondText
import io.ktor.routing.get
import io.ktor.routing.routing
import io.ktor.server.engine.embeddedServer
import io.ktor.server.netty.Netty
import io.ktor.util.KtorExperimentalAPI
import io.ktor.websocket.webSocket
import java.util.Collections
import java.util.concurrent.atomic.AtomicInteger
import kotlin.collections.LinkedHashSet

@KtorExperimentalAPI
class GameClient(val session: DefaultWebSocketSession) {
    companion object {
        var lastId = AtomicInteger(0)
    }

    private val id = lastId.getAndIncrement()
    val name = "user$id"
}

@KtorExperimentalAPI
fun main() {
    val server = embeddedServer(Netty, port = 8080) {
        mainModule()
    }
    server.start(wait = true)
}

@KtorExperimentalAPI
fun Application.mainModule() {
    install(io.ktor.websocket.WebSockets)
    routing {
        val clients = Collections.synchronizedSet(LinkedHashSet<GameClient>())
        get("/") {
            call.respondText(clients.toString(), io.ktor.http.ContentType.Text.Html)
        }
        webSocket("/") {
            val client = GameClient(this)
            clients += client
            client.session.outgoing.send(Frame.Text(clients.size.toString()))
            try {
                while (true) {
                    when (val frame = incoming.receive()) {
                        is Frame.Text -> {
                            val textToSend = "${client.name} ${frame.readText()}"
                            for (other in clients.toList()) {
                                if (other != client) {
                                    other.session.outgoing.send(Frame.Text(textToSend))
                                }
                            }
                        }
                    }
                }
            } finally {
                clients -= client
            }
        }
        webSocket("/side") {
            send(Frame.Text(clients.size.toString()))
        }
    }
}

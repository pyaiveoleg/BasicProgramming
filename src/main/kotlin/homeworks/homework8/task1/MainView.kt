package homeworks.homework7.task2

import io.ktor.util.KtorExperimentalAPI
import javafx.scene.paint.Color
import javafx.scene.text.FontWeight
import tornadofx.View
import tornadofx.action
import tornadofx.bind
import tornadofx.button
import tornadofx.form
import tornadofx.hbox
import tornadofx.label
import tornadofx.paddingLeft
import tornadofx.paddingTop
import tornadofx.px
import tornadofx.style
import tornadofx.vbox

class MainView : View("Cross-zero") {
    private val controller: MainController by inject()
    private val model = TicTacToe

    @KtorExperimentalAPI
    override val root = form {
        hbox {
            paddingTop = 5
            label("Current move: ")
            label {
                bind(model.currentMove)
            }
        }
        vbox {
            paddingTop = 10
            for (i in 0..2) {
                hbox {
                    paddingTop = 3
                    for (j in 0..2) {
                        hbox {
                            paddingLeft = 3
                            button {
                                minHeight = 50.0
                                minWidth = 50.0
                                maxHeight = 50.0
                                maxWidth = 50.0
                                bind(model.table[j][i])
                                action {
                                    controller.play(j, i)
                                }
                                style {
                                    backgroundColor += Color.LIGHTGREEN
                                    fontWeight = FontWeight.EXTRA_BOLD
                                    fontSize = 25.px
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

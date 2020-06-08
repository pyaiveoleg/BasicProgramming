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
    companion object Config {
        private const val sizeOfSquare = 50.0
        private const val sizeOfFont = 20
        private const val paddingBetweenSquares = 3
        private const val paddingBetweenBoardAndLabel = 10
        private const val paddingBetweenTopAndLabel = 5
    }

    @KtorExperimentalAPI
    override val root = form {
        hbox {
            paddingTop = paddingBetweenTopAndLabel
            label("Current move: ")
            label {
                bind(model.currentMove)
            }
        }
        vbox {
            paddingTop = paddingBetweenBoardAndLabel
            for (i in 0..2) {
                hbox {
                    paddingTop = paddingBetweenSquares
                    for (j in 0..2) {
                        hbox {
                            paddingLeft = paddingBetweenSquares
                            button {
                                minHeight = sizeOfSquare
                                minWidth = sizeOfSquare
                                maxHeight = sizeOfSquare
                                maxWidth = sizeOfSquare
                                bind(model.table[j][i])
                                action {
                                    controller.play(j, i)
                                }
                                style {
                                    backgroundColor += Color.LIGHTGREEN
                                    fontWeight = FontWeight.EXTRA_BOLD
                                    fontSize = sizeOfFont.px
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

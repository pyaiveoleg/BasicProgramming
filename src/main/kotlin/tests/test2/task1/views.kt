package tests.test2.task1

import io.ktor.util.KtorExperimentalAPI
import javafx.scene.paint.Color
import javafx.scene.text.FontWeight
import tornadofx.*

class StartView : View("Find Pairs") {
    private val heightOfWindow = 240.0
    private val widthOfWindow = 480.0
    @KtorExperimentalAPI
    override val root = form {
        prefHeight = heightOfWindow
        prefWidth = widthOfWindow

        button("Start game!") {
            action {
                replaceWith<MainView>()
            }
        }
    }
}

class MainView : View("Find Pairs") {
    private val controller: MainController by inject()
    private val sizeOfButton = 50.0
    private val sizeOfFont = 25.0

    @KtorExperimentalAPI
    override val root = form {
        vbox {
            paddingTop = 10
            for (i in 0 until controller.size) {
                hbox {
                    label {
                        bind(controller.errorMessage)
                    }
                    paddingTop = 3
                    for (j in 0 until controller.size) {
                        hbox {
                            paddingLeft = 3
                            button {
                                minHeight = sizeOfButton
                                minWidth = sizeOfButton
                                maxHeight = sizeOfButton
                                maxWidth = sizeOfButton
                                bind(controller.table[i + controller.size * j])
                                action {
                                    controller.parseClick(i, j)
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

class EndView : View("Find Pairs") {
    private val controller: MainController by inject()
    override val root = form {
        label("You won!")
        button("Return to main menu.") {
            action {
                replaceWith<StartView>()
                controller.initializeBoard(controller.size)
            }
        }
    }
}
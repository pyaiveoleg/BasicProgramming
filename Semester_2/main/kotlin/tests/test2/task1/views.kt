package tests.test2.task1

import io.ktor.util.KtorExperimentalAPI
import javafx.scene.paint.Color
import javafx.scene.text.FontWeight
import tornadofx.View
import tornadofx.form
import tornadofx.button
import tornadofx.action
import tornadofx.vbox
import tornadofx.label
import tornadofx.hbox
import tornadofx.bind
import tornadofx.paddingLeft
import tornadofx.paddingTop
import tornadofx.style
import tornadofx.px

private const val SIZE_OF_BUTTON = 50.0
private const val SIZE_OF_FONT = 25.0
private const val PADDING_OF_OBJECTS = 3
private const val HEIGHT_OF_WINDOW = 240.0
private const val WIDTH_OF_WINDOW = 480.0

class StartView : View("Find Pairs") {
    @KtorExperimentalAPI
    override val root = form {
        prefHeight = HEIGHT_OF_WINDOW
        prefWidth = WIDTH_OF_WINDOW

        button("Start game!") {
            action {
                replaceWith<MainView>()
            }
        }
    }
}

class MainView : View("Find Pairs") {
    private val controller: MainController by inject()

    @KtorExperimentalAPI
    override val root = form {
        vbox {
            for (i in 0 until controller.size) {
                hbox {
                    label {
                        bind(controller.errorMessage)
                    }
                    paddingTop = PADDING_OF_OBJECTS
                    for (j in 0 until controller.size) {
                        hbox {
                            paddingLeft = PADDING_OF_OBJECTS
                            button {
                                minHeight = SIZE_OF_BUTTON
                                minWidth = SIZE_OF_BUTTON
                                maxHeight = SIZE_OF_BUTTON
                                maxWidth = SIZE_OF_BUTTON
                                bind(controller.table[i + controller.size * j])
                                action {
                                    controller.parseClick(i, j)
                                }
                                style {
                                    backgroundColor += Color.LIGHTGREEN
                                    fontWeight = FontWeight.EXTRA_BOLD
                                    fontSize = SIZE_OF_FONT.px
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

package tests.test2.task1

import io.ktor.util.KtorExperimentalAPI
import javafx.scene.paint.Color
import javafx.scene.text.FontWeight
import tornadofx.*

class StartView : View("Find Pairs") {
    @KtorExperimentalAPI
    override val root = form {
        prefHeight = 240.0
        prefWidth = 480.0

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
        hbox {
            paddingTop = 5
        }
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
                                minHeight = 50.0
                                minWidth = 50.0
                                maxHeight = 50.0
                                maxWidth = 50.0
                                bind(controller.table[i + controller.size * j])
                                action {
                                    controller.parseClick(i, j)
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

class EndView : View("Find Pairs") {
    private val controller: MainController by inject()
    override val root = form {
        prefHeight = 240.0
        prefWidth = 480.0
        label("You won!")
        button("Return to main menu.") {
            action {
                replaceWith<StartView>()
                controller.initializeBoard(controller.size)
            }
        }
    }
}
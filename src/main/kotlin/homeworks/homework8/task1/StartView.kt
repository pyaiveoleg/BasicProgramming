package homeworks.homework7.task2

import io.ktor.util.KtorExperimentalAPI
import javafx.scene.control.ToggleGroup
import tornadofx.View
import tornadofx.action
import tornadofx.button
import tornadofx.form
import tornadofx.label
import tornadofx.radiobutton
import tornadofx.vbox

class StartView : View("Cross-zero") {
    val controller: MainController by inject()
    companion object Config {
        private const val HEIGHT = 240.0
        private const val WIDTH = 480.0
    }

    @KtorExperimentalAPI
    override val root = form {
        prefHeight = HEIGHT
        prefWidth = WIDTH

        var mode = ""
        val chooseMode = ToggleGroup()
        vbox {
            label("Choose game mode")
            radiobutton("Easy", chooseMode) {
                action {
                    mode = "Easy"
                }
            }
            radiobutton("Hard", chooseMode) {
                action {
                    mode = "Hard"
                }
            }
            radiobutton("Two players", chooseMode) {
                action {
                    mode = "Two players"
                }
            }
        }
        button("Submit") {
            action {
                controller.changeMode(mode)
                if (mode == "Two players") {
                    replaceWith<OnlineOfflineView>()
                } else {
                    replaceWith<ChooseSideView>()
                }
            }
        }
    }
}

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

object StartView : View("Cross-zero") {
    private val controller: MainController by inject()

    private const val height = 240.0
    private const val width = 480.0

    @KtorExperimentalAPI
    override val root = form {
        prefHeight = height
        prefWidth = width

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

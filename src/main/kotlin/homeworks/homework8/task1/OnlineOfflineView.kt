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

object OnlineOfflineView : View("Cross-zero") {
    private val controller: MainController by inject()

    @KtorExperimentalAPI
    override val root = form {
        var mode = ""
        val chooseMode = ToggleGroup()
        vbox {
            label("Choose game mode")
            radiobutton("Online", chooseMode) {
                action {
                    mode = "Online"
                }
            }
            radiobutton("Offline", chooseMode) {
                action {
                    mode = "Two players"
                }
            }
        }
        button("Submit") {
            action {
                controller.changeMode(mode)
                replaceWith<MainView>()
            }
        }
    }
}

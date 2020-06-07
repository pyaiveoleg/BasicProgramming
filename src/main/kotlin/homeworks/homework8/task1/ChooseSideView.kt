package homeworks.homework7.task2

import javafx.scene.control.ToggleGroup
import tornadofx.View
import tornadofx.action
import tornadofx.button
import tornadofx.form
import tornadofx.label
import tornadofx.radiobutton
import tornadofx.vbox

class ChooseSideView : View("Cross-zero") {
    private val controller: MainController by inject()

    override val root = form {
        var side: Int? = null
        val chooseSide = ToggleGroup()
        vbox {
            label("Choose your side")
            radiobutton("First", chooseSide) {
                action {
                    side = 1
                }
            }
            radiobutton("Second", chooseSide) {
                action {
                    side = 2
                }
            }
        }
        button("Submit") {
            action {
                controller.changeSide(side)
                replaceWith<MainView>()
            }
        }
    }
}

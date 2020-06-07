package homeworks.homework7.task2

import javafx.scene.control.ToggleGroup
import tornadofx.View
import tornadofx.action
import tornadofx.button
import tornadofx.form
import tornadofx.label
import tornadofx.radiobutton
import tornadofx.vbox

object ChooseSideView : View("Cross-zero") {
    private val controller: MainController by inject()
    private const val firstSide = 1
    private const val secondSide = 2

    override val root = form {
        var side: Int? = null
        val chooseSide = ToggleGroup()
        vbox {
            label("Choose your side")
            radiobutton("First", chooseSide) {
                action {
                    side = firstSide
                }
            }
            radiobutton("Second", chooseSide) {
                action {
                    side = secondSide
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

package tests.test2.task1

import javafx.application.Application
import javafx.stage.Stage
import tornadofx.App
import tornadofx.find

class FindPairs : App(StartView::class) {
    override fun start(stage: Stage) {
        val controller = find(MainController::class)
        val size = parameters.named["size"]?.toInt()
        if (size == null) {
            print("You haven't passed size")
            return
        }
        if (size % 2 == 1) {
            print("Size cannot be odd")
            return
        }
        controller.initializeBoard(size)
        print(controller.size)
        super.start(stage)
    }
}

fun main(args: Array<String>) {
    Application.launch(FindPairs::class.java, *args)
}

package tests.test2.task1

import javafx.application.Application
import tornadofx.App
import tornadofx.find

class FindPairsApp : App(StartView::class)

fun main(args: Array<String>) {
    if (args.isEmpty()) {
        print("You haven't passed size")
        return
    }
    val size = args[0].toInt()
    val controller = find(MainController::class)

    if (size % 2 == 1) {
        print("Size cannot be odd")
        return
    }
    
    controller.initializeBoard(size)
    Application.launch(FindPairsApp::class.java)
}

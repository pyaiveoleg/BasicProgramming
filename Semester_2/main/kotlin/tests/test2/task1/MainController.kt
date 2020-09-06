package tests.test2.task1

import javafx.beans.property.SimpleStringProperty
import tornadofx.Controller

class MainController : Controller() {
    var size = 0
    private var model = FindPairsGame(size)
    var table = Array(size * size) { SimpleStringProperty("") }
    private var wereEqual = true
    private var firstCell = -1
    private var secondCell = -1
    val errorMessage = SimpleStringProperty("")

    fun initializeBoard(size: Int) {
        this.size = size
        table = Array(size * size) { SimpleStringProperty("") }
        model = FindPairsGame(size)
    }

    fun parseClick(x: Int, y: Int) {
        if (!wereEqual) {
            table[firstCell].value = ""
            table[secondCell].value = ""
            wereEqual = true
        } // clear

        val result = model.addClick(x, y)
        if (result.isEmpty()) {
            return
        }

        firstCell = result[0]
        secondCell = result[1]
        val firstValue = result[2].toString()
        val secondValue = result[result.size - 1].toString()
        table[firstCell].value = firstValue
        table[secondCell].value = secondValue

        if (firstValue != secondValue) {
            wereEqual = false
        }

        if (model.isEnd()) {
            find(MainView::class).replaceWith<EndView>()
        }
    }
}

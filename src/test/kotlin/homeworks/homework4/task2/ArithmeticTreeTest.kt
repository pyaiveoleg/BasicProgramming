package homeworks.homework4.task2

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.assertEquals
import java.io.File

internal class ArithmeticTreeTest {
    @Test
    fun countValue_treeWithThreeOperators() {
        val file = File("./src/test/resources/homeworks/homework4/task2/treeWithThreeOperators.txt")
        val tree = ArithmeticTree()
        tree.importTree(file)
        tree.root.calculateValue()
        assertEquals(17.0, tree.root.value)
    }

    @Test
    fun countValue_treeWithOneElement() {
        val file = File("./src/test/resources/homeworks/homework4/task2/treeWithOneElement.txt")
        val tree = ArithmeticTree()
        tree.importTree(file)
        tree.root.calculateValue()
        assertEquals(1.0, tree.root.value)
    }

    @Test
    fun countValue_treeWithOneSum() {
        val file = File("./src/test/resources/homeworks/homework4/task2/treeWithOneSum.txt")
        val tree = ArithmeticTree()
        tree.importTree(file)
        tree.root.calculateValue()
        assertEquals(4.0, tree.root.value)
    }

    @Test
    fun countValue_treeWithOneDeletion() {
        val file = File("./src/test/resources/homeworks/homework4/task2/treeWithOneDeletion.txt")
        val tree = ArithmeticTree()
        tree.importTree(file)
        tree.root.calculateValue()
        assertEquals(0.2, tree.root.value)
    }

    @Test
    fun countValue_treeWithManySums() {
        val file = File("./src/test/resources/homeworks/homework4/task2/treeWithManySums.txt")
        val tree = ArithmeticTree()
        tree.importTree(file)
        tree.root.calculateValue()
        assertEquals(21.0, tree.root.value)
    }

    @Test
    fun countValue_complicatedTreeWithAllOperations() {
        val file = File("./src/test/resources/homeworks/homework4/task2/complicatedTreeWithAllOperations.txt")
        val tree = ArithmeticTree()
        tree.importTree(file)
        tree.root.calculateValue()
        assertEquals(-12.0, tree.root.value)
    }
}
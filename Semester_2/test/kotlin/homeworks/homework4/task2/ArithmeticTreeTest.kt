package homeworks.homework4.task2

import org.junit.jupiter.api.Assertions.assertEquals
import org.junit.jupiter.api.Test

internal class ArithmeticTreeTest {
    @Test
    fun countValue_treeWithThreeOperators() {
        val tree = ArithmeticTree("(+ (* 1 2) (* 3 5))")
        assertEquals(17.0, tree.getValue())
    }

    @Test
    fun countValue_treeWithOneElement() {
        val tree = ArithmeticTree("1")
        assertEquals(1.0, tree.getValue())
    }

    @Test
    fun countValue_treeWithOneSum() {
        val tree = ArithmeticTree("(+ 2 2)")
        assertEquals(4.0, tree.getValue())
    }

    @Test
    fun countValue_treeWithOneDeletion() {
        val tree = ArithmeticTree("(/ 1 5)")
        assertEquals(0.2, tree.getValue())
    }

    @Test
    fun countValue_treeWithManySums() {
        val tree = ArithmeticTree("(+ (+ (+ (+ (+ 1 2) 3) 4) 5) 6)")
        assertEquals(21.0, tree.getValue())
    }

    @Test
    fun countValue_complicatedTreeWithAllOperations() {
        val tree = ArithmeticTree("(* (+ 1 2) (- (/ 4 4) 5))")
        assertEquals(-12.0, tree.getValue())
    }
}

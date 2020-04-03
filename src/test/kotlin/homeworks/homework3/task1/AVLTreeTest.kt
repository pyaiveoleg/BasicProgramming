package homeworks.homework3.task1

import org.junit.jupiter.api.Assertions.assertEquals
import org.junit.jupiter.api.Test

internal class AVLTreeTest {
    @Test
    fun containsElement_emptyTree() {
        val tree = AVLTree<Int, Int>()
        assertEquals(false, tree.containsElement(0))
    }

    @Test
    fun containsElement_treeWithOneElementContainsKey() {
        val tree = AVLTree<Int, Int>()
        tree.addElement(0, 0)
        assertEquals(true, tree.containsElement(0))
    }

    @Test
    fun containsElement_treeWithOneElementNotContainsKey() {
        val tree = AVLTree<Int, Int>()
        tree.addElement(1, 0)
        assertEquals(false, tree.containsElement(0))
    }

    @Test
    fun containsElement_treeContainsKey() {
        val tree = AVLTree<Int, Int>()
        tree.addElement(0, 0)
        tree.addElement(1, 0)
        tree.addElement(-1, 0)
        tree.addElement(2, 0)
        assertEquals(true, tree.containsElement(1))
    }

    @Test
    fun containsElement_notContainsKey() {
        val tree = AVLTree<Int, Int>()
        tree.addElement(0, 0)
        tree.addElement(1, 0)
        tree.addElement(-1, 0)
        tree.addElement(2, 0)
        assertEquals(false, tree.containsElement(-5))
    }

    @Test
    fun addAndDeleteElement_emptyTree() {
        val actualTree = AVLTree<Int, Int>()
        val tree = AVLTree<Int, Int>()
        tree.addElement(1, -5)
        tree.deleteElement(1)
        assertEquals(true, tree.equalsToTree(actualTree))
    }

    @Test
    fun addAndDeleteElement_treeWithSeveralElements() {
        val actualTree = AVLTree<Int, Int>()
        val tree = AVLTree<Int, Int>()
        tree.addElement(1, -5)
        tree.addElement(2, 4)
        tree.addElement(3, -1)
        tree.addElement(4, -2)
        actualTree.addElement(3, -1)
        actualTree.addElement(2, 4)
        actualTree.addElement(4, -2)
        tree.deleteElement(1)
        assertEquals(true, tree.equalsToTree(actualTree))
    }

    @Test
    fun getValue_treeWithOneElementNotContainsKey() {
        val tree = AVLTree<Int, Int>()
        tree.addElement(1, 0)
        assertEquals(null, tree.getValue(0))
    }

    @Test
    fun getValue_treeWithOneElementContainsKey() {
        val tree = AVLTree<Int, Int>()
        tree.addElement(1, -5)
        assertEquals(-5, tree.getValue(1))
    }

    @Test
    fun getValue_emptyTree() {
        val tree = AVLTree<Int, Int>()
        assertEquals(null, tree.getValue(1))
    }

    @Test
    fun getValue_treeWithSeveralElementsContainsKey() {
        val tree = AVLTree<Int, Int>()
        tree.addElement(1, -5)
        tree.addElement(2, 4)
        tree.addElement(3, -1)
        tree.addElement(4, -2)
        assertEquals(-1, tree.getValue(3))
    }

    @Test
    fun getValue_treeWithSeveralElementsNotContainsKey() {
        val tree = AVLTree<Int, Int>()
        tree.addElement(1, -5)
        tree.addElement(2, 4)
        tree.addElement(3, -1)
        tree.addElement(4, -2)
        assertEquals(null, tree.getValue(5))
    }
}

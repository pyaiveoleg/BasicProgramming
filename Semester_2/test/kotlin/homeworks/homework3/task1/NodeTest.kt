package homeworks.homework3.task1

import org.junit.jupiter.api.Assertions.assertEquals
import org.junit.jupiter.api.Assertions.assertNull
import org.junit.jupiter.api.Test

internal class NodeTest {
    @Test
    fun findNodeWithMaxKeyInSubtree_singleNode() {
        val node = Node(0, 0)
        assert(node.equalTo(node.findNodeWithMaxKeyInSubtree()))
    }

    @Test
    fun findNodeWithMaxKeyInSubtree_nodeWithLeftChild() {
        val node = Node(0, 0)
        val leftChild = Node(-5, 0)
        node.leftChild = leftChild
        assert(node.equalTo(node.findNodeWithMaxKeyInSubtree()))
    }

    @Test
    fun findNodeWithMaxKeyInSubtree_nodeWithRightChild() {
        val node = Node(0, 0)
        val rightChild = Node(5, 0)
        node.rightChild = rightChild
        assert(rightChild.equalTo(node.findNodeWithMaxKeyInSubtree()))
    }

    @Test
    fun findNodeWithMaxKeyInSubtree_complicatedNode() {
        val node = Node(0, 0)
        val rightChild = Node(5, 0)
        node.rightChild = rightChild
        val leftChild = Node(-5, 0)
        node.leftChild = leftChild
        assert(rightChild.equalTo(node.findNodeWithMaxKeyInSubtree()))
    }

    @Test
    fun removeNodeWithMaxKeyInSubtree_singleNode() {
        val node = Node(0, 0)
        assertNull(node.removeNodeWithMaxKeyInSubtree())
    }

    @Test
    fun removeNodeWithMaxKeyInSubtree_nodeWithLeftChild() {
        val node = Node(0, 0)
        val leftChild = Node(-5, 0)
        node.leftChild = leftChild
        assert(leftChild.equalTo(node.removeNodeWithMaxKeyInSubtree()))
    }

    @Test
    fun removeNodeWithMaxKeyInSubtree_nodeWithRightChild() {
        val node = Node(0, 0)
        val rightChild = Node(5, 0)
        node.rightChild = rightChild
        assert(node.equalTo(node.removeNodeWithMaxKeyInSubtree()))
    }

    @Test
    fun removeNodeWithMaxKeyInSubtree_complicatedNode() {
        val node = Node(0, 0)
        val rightChild = Node(5, 0)
        node.rightChild = rightChild
        val leftChild = Node(-5, 0)
        node.leftChild = leftChild
        assert(node.equalTo(node.removeNodeWithMaxKeyInSubtree()))
    }

    @Test
    fun toString_singleNode() {
        val node = Node(0, 0)
        assertEquals(node.toString(), "([key: 0, value: 0] null null)")
    }

    @Test
    fun toString_nodeWithLeftChild() {
        val node = Node(0, 0)
        val leftChild = Node(-5, 0)
        node.leftChild = leftChild
        assertEquals(node.toString(), "([key: 0, value: 0] ([key: -5, value: 0] null null) null)")
    }

    @Test
    fun toString_nodeWithRightChild() {
        val node = Node(0, 0)
        val rightChild = Node(5, 0)
        node.rightChild = rightChild
        assertEquals(node.toString(), "([key: 0, value: 0] null ([key: 5, value: 0] null null))")
    }

    @Test
    fun toString_complicatedNode() {
        val node = Node(0, 0)
        val rightChild = Node(5, 0)
        node.rightChild = rightChild
        val leftChild = Node(-5, 0)
        node.leftChild = leftChild
        assertEquals(
            node.toString(),
            "([key: 0, value: 0] ([key: -5, value: 0] null null) ([key: 5, value: 0] null null))"
        )
    }
}

package homeworks.homework4.task2

import java.io.File

class ArithmeticTree {
    var root: Node = Node()
    private var stringWithTree = ""

    class Node {
        private val listOfOperators = arrayListOf('+', '-', '*', '/')
        var value = 0.0
        private var operator: Char? = null
        private var leftChild: Node? = null
        private var rightChild: Node? = null

        fun calculateValue(): Double {
            val operator = this.operator ?: return value
            leftChild?.calculateValue()
            rightChild?.calculateValue()
            val leftValue = leftChild?.value ?: throw IllegalArgumentException("First operand doesn't exist.")
            val rightValue = rightChild?.value ?: throw IllegalArgumentException("Second operand doesn't exist.")
            if (operator in listOfOperators) {
                when (operator) {
                    '+' -> value = leftValue + rightValue
                    '-' -> value = leftValue - rightValue
                    '*' -> value = leftValue * rightValue
                    '/' -> value = leftValue / rightValue
                }
                return value
            }
            throw IllegalArgumentException("Illegal operator") //Operator isn't in list of operators
        }

        fun importSubtree(currentIndex: Int, stringWithTree: String): Int {
            var leftChildWasCreated = false
            if (stringWithTree[currentIndex].isDigit()) { //tree contains of one element
                this.value = stringWithTree.slice(currentIndex until stringWithTree.length - 1).toDouble()
                return stringWithTree.length
            }
            var index = currentIndex
            while (index < stringWithTree.length){
                when {
                    stringWithTree[index] in listOfOperators -> {
                        this.operator = stringWithTree[index]
                        index++
                    }
                    stringWithTree[index] == '(' -> {
                        if (leftChildWasCreated) {
                            rightChild = Node()
                            index = rightChild?.importSubtree(index + 1, stringWithTree) ?: 0
                        } else {
                            leftChildWasCreated = true
                            leftChild = Node()
                            index = leftChild?.importSubtree(index + 1, stringWithTree) ?: 0
                        }
                    }
                    stringWithTree[index] == ')' -> {
                        return index + 1
                    }
                    stringWithTree[index].isDigit() -> {
                        var endOfNumber: Int
                        if (leftChildWasCreated) {
                            endOfNumber = stringWithTree.slice(index until stringWithTree.length).indexOf(')')
                            rightChild = Node()
                            rightChild?.operator = null
                            rightChild?.value = stringWithTree.slice(index until index + endOfNumber).toDouble()
                        } else {
                            endOfNumber = stringWithTree.slice(index until stringWithTree.length).indexOf(' ')
                            leftChildWasCreated = true
                            leftChild = Node()
                            leftChild?.operator = null
                            leftChild?.value = stringWithTree.slice(index until index + endOfNumber).toDouble()
                        }
                        index += endOfNumber
                    }
                    stringWithTree[index] == ' ' -> {
                        index++
                    }
                }
            }
            return index
        }

        fun printSubtree(): String {
            return "([operator: $operator, value: $value] ${leftChild?.printSubtree()} ${rightChild?.printSubtree()})" //а если оператор
        }
    }

    fun importTree(inputFile: File) {
        stringWithTree = inputFile.bufferedReader().readLine()
        root.importSubtree(1, stringWithTree)
    }

    fun printTree() {
        print("This is a tree: ${root.printSubtree()}\n")
    }
}

package homeworks.homework2.task2

fun removeRepeatingElements(originalArray: Array<Any>): Array<Any> {
    return originalArray.reversed().distinct().reversed().toTypedArray()
}

fun main() {
    println("Please, write down original string:")
    val inputString = readLine() ?: run {
        print("String cannot be null.")
        return
    }
    val originalArray = inputString.split(" ").map { it.toInt() }
    println("This is distincted list:\n" + removeRepeatingElements(originalArray.toTypedArray()))
}

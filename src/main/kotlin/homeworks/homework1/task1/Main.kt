package homeworks.homework1.task1

fun exchangeStartAndEnd(beginningLength: Int, endingLength: Int, array: MutableList<Int>): MutableList<Int> {
    val arrayLength = beginningLength + endingLength
    if (array.size != arrayLength) {
        print(array.size)
        throw IllegalArgumentException("M + N should be equal to array length")
    }
    array.subList(0, beginningLength).reverse()
    array.subList(beginningLength, arrayLength).reverse()
    array.reverse()
    return array
}

fun main() {
    val scan = java.util.Scanner(System.`in`)
    println("Please, write down length of beginning (M) and ending (N) of the array: ")
    val beginningLength = scan.nextInt()
    val endingLength = scan.nextInt()
    println("Please, write down array: ")
    val array = readLine()?.split(" ")?.map { it.toInt() }?.toMutableList()
    if (array == null) {
        print("array cannot be null")
        return
    }

    try {
        val parsedArray = exchangeStartAndEnd(beginningLength, endingLength, array)
        println("Parsed array: ")
        println(parsedArray.joinToString(" "))
    } catch (illegalQuantityOfNumbers: IllegalArgumentException) {
        println(illegalQuantityOfNumbers.message)
    }
}

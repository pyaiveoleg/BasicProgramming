package homeworks.homework1.task1

fun exchangeStartAndEnd(beginningLength: Int, endingLength: Int, array: IntArray): IntArray {
    val arrayLength = beginningLength + endingLength
    if (array.size != arrayLength) {
        throw IndexOutOfBoundsException("M + N should be equal to array length")
    }
    val list = array.toMutableList()
    list.subList(0, beginningLength).reverse()
    list.subList(beginningLength, arrayLength).reverse()
    list.reverse()
    return list.toIntArray()
}

fun main() {
    val scan = java.util.Scanner(System.`in`)
    println("Please, write down length of beginning (M) and ending (N) of the array: ")
    val beginningLength = scan.nextInt()
    val endingLength = scan.nextInt()
    val arrayLength = beginningLength + endingLength
    val array = IntArray(arrayLength) { 0 }

    println("Please, write down array: ")
    for (i in 0 until arrayLength) {
        array[i] = scan.nextInt()
    }

    println("Parsed array: ")
    println(exchangeStartAndEnd(beginningLength, endingLength, array).joinToString(" "))
}

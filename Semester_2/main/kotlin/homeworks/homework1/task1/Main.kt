package homeworks.homework1.task1

fun exchangeStartAndEnd(beginningLength: Int, endingLength: Int, array: MutableList<Int>): MutableList<Int> {
    val arrayLength = beginningLength + endingLength
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
    if (array.size != beginningLength + endingLength) {
        print("M + N should be equal to array length")
        return
    }

    println("Parsed array: ${exchangeStartAndEnd(beginningLength, endingLength, array)}")
}

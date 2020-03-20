package semester_2.homework_1.task_1

fun reverse(start: Int, end: Int, array: IntArray) {
    array.toList().subList(start, end).toTypedArray().reverse()
}

fun exchangeStartAndEnd(beginningLength: Int, endingLength: Int, array: IntArray) {
    val arrayLength = beginningLength + endingLength
    array.toList().subList(0, endingLength).toTypedArray().reverse()
    array.toList().subList(endingLength, arrayLength).toTypedArray().reverse()
    array.toList().subList(0, arrayLength).toTypedArray().reverse()
//    reverse(0, endingLength, array)
//    reverse(endingLength, arrayLength, array)
//    reverse(0, arrayLength, array)
}

fun main() {
    val scan = java.util.Scanner(System.`in`)
    println("Please, write down length of beginning (M) and ending (N) of the array: ")
    val beginningLength = scan.nextInt()
    val endingLength = scan.nextInt()
    val arrayLength = beginningLength + endingLength
    val array = IntArray(arrayLength) { 0 }

    println("Please, write down array: ")
    for (i in 0..arrayLength - 1) {
        array[i] = scan.nextInt()
    }

    exchangeStartAndEnd(beginningLength, endingLength, array)

    println("Parsed array: ")
    for (i in 0 until arrayLength) {
        print("${array.get(i)} ")
    }
}

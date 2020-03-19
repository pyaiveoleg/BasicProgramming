val scan = java.util.Scanner(System.`in`)

fun swap(firstElement: Int, secondElement: Int, array: IntArray)
{
    val temporary = array.get(firstElement)
    array.set(firstElement, array.get(secondElement))
    array.set(secondElement, temporary)
}

fun reverse(start: Int, end: Int, array: IntArray)
{
    val endOfCycle = (start + end) / 2
    for (i in start until endOfCycle) {
        swap(i, start + end - 1 - i, array)
    }
}

fun exchangeStartAndEnd(beginningLength: Int, endingLength: Int, array: IntArray)
{
    val arrayLength = beginningLength + endingLength
    reverse(0, endingLength, array)
    reverse(endingLength, arrayLength, array)
    reverse(0, arrayLength, array)
}

fun main()
{
    println("Please, write down length of beginning (M) and ending (N) of the array: ")
    val beginningLength = scan.nextInt()
    val endingLength = scan.nextInt()
    val arrayLength = beginningLength + endingLength
    val array = IntArray(arrayLength, {0})

    println("Please, write down array: ")
    for (i in 0 .. arrayLength - 1)
    {
        array[i] = scan.nextInt()
    }

    exchangeStartAndEnd(beginningLength, endingLength, array)

    println("Parsed array: ")
    for (i in 0 until arrayLength)
    {
        print("${array.get(i)} ")
    }
}

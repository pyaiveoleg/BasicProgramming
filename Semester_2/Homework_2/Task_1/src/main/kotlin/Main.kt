import java.util.Scanner
val scan = Scanner(System.`in`)

fun removeRepeatingElements(originalArray: Array<Int>) : Array<Int>
{
    return originalArray.distinct().toTypedArray()
}

fun main()
{
    println("Please, write down quantity of numbers in your array:")
    val arrayLength = scan.nextInt()
    val originalList = Array<Int>(arrayLength){0}
    println("Please, write down list of integer values:")
    for (i in 0 until arrayLength)
    {
        originalList[i] = scan.nextInt()
    }
    println("This is distincted list:\n" + removeRepeatingElements(originalList))
}

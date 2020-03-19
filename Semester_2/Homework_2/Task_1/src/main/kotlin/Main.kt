import java.util.Scanner
val scan = Scanner(System.`in`)

fun distinct(originalList: List<Int>) : List<Int>
{
    return originalList.distinct()
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
    println("This is distincted list:\n" + originalList.distinct())
}

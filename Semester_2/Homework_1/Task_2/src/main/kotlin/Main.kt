val scan = java.util.Scanner(System.`in`)

fun recursiveFactorial(number: Int) : Int
{
    if (number > 1)
    {
        return number * recursiveFactorial(number - 1)
    }
    return number
}

fun iterativeFactorial(number: Int) : Int
{
    var factorial = 1
    for (i in 2 .. number)
    {
        factorial = factorial * i
    }
    return factorial
}

fun main()
{
    println("Please, write down N:");
    var number = scan.nextInt()

    println("Factorial of N (recursive): ${recursiveFactorial(number)}");
    println("Factorial of N (iterative): ${iterativeFactorial(number)}")
}

fun recursiveFactorial(number: Int): Int {
    if (number < 0) {
        throw IllegalArgumentException("Number must be positive")
    }

    if (number == 0) {
        return 1
    }

    if (number > 1) {
        return number * recursiveFactorial(number - 1)
    }
    return number
}

fun iterativeFactorial(number: Int): Int? {
    if (number < 0) {
        throw IllegalArgumentException("Number must be positive")
    }

    if (number == 0) {
        return 1
    }

    var factorial = 1
    for (i in 2..number) {
        factorial = factorial * i
    }
    return factorial
}

fun main() {
    val scan = java.util.Scanner(System.`in`)
    println("Please, write down N:");
    val number = scan.nextInt()

    println("Factorial of N (recursive): ${recursiveFactorial(number)}");
    println("Factorial of N (iterative): ${iterativeFactorial(number)}")
}

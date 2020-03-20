val scan = java.util.Scanner(System.`in`)

fun checkPalindrome(inputString: String): Boolean {
    val stringLength = inputString.length

    for (i in 0..(stringLength / 2 - 1)) {
        if (inputString[i] != inputString[stringLength - i - 1]) {
            return false
        }
    }

    return true
}

fun main() {
    println("Please, write down the string: ")
    val inputString = scan.nextLine()

    if (checkPalindrome(inputString)) {
        println("String is palindrome")
    } else {
        println("String is not palindrome")
    }
}

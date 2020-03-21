package homeworks.homework1.task4

fun checkPalindrome(inputString: String): Boolean {
    val stringLength = inputString.length

    for (i in 0 until stringLength / 2) {
        if (inputString[i] != inputString[stringLength - i - 1]) {
            return false
        }
    }

    return true
}

fun main() {
    println("Please, write down the string: ")
    val inputString = readLine()!!

    if (checkPalindrome(inputString)) {
        println("String is palindrome")
    } else {
        println("String is not palindrome")
    }
}

package homeworks.homework4.task1

class SimpleHash : HashFunction {
    override fun calculateHash(string: String): Int {
        var hash = 0
        for (character in string) {
            hash += character.toInt()
        }
        return hash
    }
}

package homeworks.homework7.task2

class EasyBot {
    fun makeMove(board: MutableList<Int>): Array<Int> {
        val availablePoints = mutableListOf<Int>()
        for (cell in board) {
            if (cell in 0 until 9) {
                availablePoints.add(cell)
            }
        }
        val pointToMove = availablePoints.shuffled()[0] // random point
        val xMove = pointToMove % 3
        val yMove: Int = pointToMove / 3
        return arrayOf(xMove, yMove)
    }
}

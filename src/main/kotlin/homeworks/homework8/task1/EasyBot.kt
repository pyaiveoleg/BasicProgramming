package homeworks.homework7.task2

object EasyBot {
    private const val boardSide = 3

    fun makeMove(board: MutableList<Int>): IntArray {
        val availablePoints = mutableListOf<Int>()
        for (cell in board) {
            if (cell in 0 until boardSide * boardSide) {
                availablePoints.add(cell)
            }
        }
        val pointToMove = availablePoints.shuffled()[0] // random point
        val xMove = pointToMove % boardSide
        val yMove: Int = pointToMove / boardSide
        return intArrayOf(xMove, yMove)
    }
}

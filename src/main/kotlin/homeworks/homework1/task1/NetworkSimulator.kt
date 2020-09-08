package homeworks.homework1.task1

import kotlin.random.Random

class NetworkSimulator(private val network: Network) {
    fun nextTurn() {
        val randomNumber = Random.nextDouble(0.0, 1.0)
        for (computer in network.computers) {
            if (!computer.isInfected) {
                continue
            }
            for (computerIndex in computer.connected) {
                val computerToInfect = this.network.computers[computerIndex]
                if (randomNumber < computerToInfect.OS.probabilityOfInfection) {
                    computerToInfect.isInfected = true
                }
            }
        }
    }

    fun getInfectedComputersList(): MutableList<Int> {
        val infectedComputersList = mutableListOf<Int>()
        for (computerIndex in network.computers.indices) {
            if (network.computers[computerIndex].isInfected) {
                infectedComputersList.add(computerIndex)
            }
        }
        return infectedComputersList
    }
}

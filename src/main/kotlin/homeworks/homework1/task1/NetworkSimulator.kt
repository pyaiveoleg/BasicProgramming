package homeworks.homework1.task1

import kotlin.random.Random

class NetworkSimulator(private val network: Network) {
    fun nextTurn() {
        val willInfected = mutableSetOf<Int>()
        for ((index, computer) in network.computers.withIndex()) {
            val randomNumber = Random.nextDouble(0.0, 1.0)
            if (!computer.isInfected) {
                continue
            }
            for (computerIndex in network.adjacencyMatrix[index]) {
                val computerToInfect = this.network.computers[computerIndex]

                if (randomNumber < network.probabilitiesOfInfection.getValue(computerToInfect.operatingSystem)) {
                    willInfected.add(computerIndex)
                }
            }
        }

        for (computerIndex in willInfected) {
            network.computers[computerIndex].isInfected = true
        }
    }

    fun getInfectedComputersList(): List<Int> {
        return network.computers.indices.filter { network.computers[it].isInfected }
    }
}

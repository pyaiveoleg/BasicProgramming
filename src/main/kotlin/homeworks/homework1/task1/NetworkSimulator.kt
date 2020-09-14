package homeworks.homework1.task1

class NetworkSimulator(val network: Network, private val probabilityGenerator: RandomProbabilityGenerator) {
    fun nextTurn() {
        val willInfected = mutableSetOf<Int>()
        for ((index, computer) in network.computers.withIndex()) {
            if (!computer.isInfected) {
                continue
            }

            for (computerIndex in network.adjacencyMatrix[index]) {
                val randomNumber = probabilityGenerator.generateProbability()
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

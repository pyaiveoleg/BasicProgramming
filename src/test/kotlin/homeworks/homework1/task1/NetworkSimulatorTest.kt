package homeworks.homework1.task1

import kotlinx.serialization.json.Json
import org.junit.jupiter.api.Assertions.*
import org.junit.jupiter.api.Test
import java.io.File

internal class NetworkSimulatorTest {
    companion object Config {
        const val QUANTITY_OF_ITERATIONS = 1000
    }

    @Test
    fun nextTurn_emptyNetwork() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/empty.json").readText()
        )
        val networkSimulator = NetworkSimulator(network, ActualRandom())
        networkSimulator.nextTurn()
        assertEquals(listOf<Int>(), networkSimulator.getInfectedComputersList())
    }

    @Test
    fun getInfectedComputersList_emptyNetwork() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/empty.json").readText()
        )
        val networkSimulator = NetworkSimulator(network, ActualRandom())
        assertEquals(listOf<Int>(), networkSimulator.getInfectedComputersList())
    }

    @Test
    fun nextTurn_allInfected() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/allInfected.json").readText()
        )
        val networkSimulator = NetworkSimulator(network, ActualRandom())
        networkSimulator.nextTurn()
        assertEquals(listOf(0, 1, 2, 3, 4), networkSimulator.getInfectedComputersList())
    }

    @Test
    fun getInfectedComputersList_allInfected() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/allInfected.json").readText()
        )
        val networkSimulator = NetworkSimulator(network, ActualRandom())
        assertEquals(listOf(0, 1, 2, 3, 4), networkSimulator.getInfectedComputersList())
    }

    @Test
    fun nextTurn_noInfected() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/noInfected.json").readText()
        )
        val networkSimulator = NetworkSimulator(network, ActualRandom())
        networkSimulator.nextTurn()
        assertEquals(listOf<Int>(), networkSimulator.getInfectedComputersList())
    }

    @Test
    fun getInfectedComputersList_noInfected() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/noInfected.json").readText()
        )
        val networkSimulator = NetworkSimulator(network, ActualRandom())
        assertEquals(listOf<Int>(), networkSimulator.getInfectedComputersList())
    }

    @Test
    fun nextTurn_complicatedGraphProbability100() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/complicatedGraphProbability100.json").readText()
        )
        val networkSimulator = NetworkSimulator(network, ActualRandom())
        networkSimulator.nextTurn()
        for (number in 0..4) {
            assert(networkSimulator.getInfectedComputersList().contains(number))
        }
    }

    @Test
    fun nextTurn_oneInfectedCenterProbability100() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/oneInfectedCenterProbability100.json").readText()
        )
        val networkSimulator = NetworkSimulator(network, ActualRandom())
        networkSimulator.nextTurn()
        for (number in 0..4) {
            assert(networkSimulator.getInfectedComputersList().contains(number))
        }
    }

    @Test
    fun nextTurn_probabilityIsZero() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/probabilityIsZero.json").readText()
        )
        val networkSimulator = NetworkSimulator(network, ActualRandom())
        for (iterations in 0..QUANTITY_OF_ITERATIONS) {
            networkSimulator.nextTurn()
            for (number in 0..3) {
                assertFalse(networkSimulator.getInfectedComputersList().contains(number))
            }
            assert(networkSimulator.getInfectedComputersList().contains(4))
        }
    }

    @Test
    fun nextTurn_oneLine() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/oneLine.json").readText()
        )
        val networkSimulator = NetworkSimulator(network, ActualRandom())
        networkSimulator.nextTurn()
        assert(networkSimulator.getInfectedComputersList().contains(0))
        assertFalse(networkSimulator.getInfectedComputersList().contains(2))
        assertFalse(networkSimulator.getInfectedComputersList().contains(3))
    }

    @Test
    fun nextTurn_oneLineProbabilityIs100() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/oneLineProbability100.json").readText()
        )
        val networkSimulator = NetworkSimulator(network, ActualRandom())
        networkSimulator.nextTurn()
        assert(networkSimulator.getInfectedComputersList().contains(0))
        assert(networkSimulator.getInfectedComputersList().contains(1))
        assertFalse(networkSimulator.getInfectedComputersList().contains(2))
    }

    @Test
    fun nextTurn_oneUninfectedProbability100() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/oneUninfectedProbability100.json").readText()
        )
        val networkSimulator = NetworkSimulator(network, ActualRandom())
        networkSimulator.nextTurn()
        for (number in 0..2) {
            assert(networkSimulator.getInfectedComputersList().contains(number))
        }
    }

    // probabilities below are not 100% and not 0%, so we check that infected computers remain infected
    // and not adjacent to infected can't infect in each step

    private fun checkStep(networkSimulator: NetworkSimulator) {
        val previousInfectedList = networkSimulator.getInfectedComputersList()
        networkSimulator.nextTurn()

        for (computer in 0..networkSimulator.network.size) {
            if (computer in previousInfectedList) {
                assert(networkSimulator.getInfectedComputersList().contains(computer))
                continue
            }

            var isAdjacentToInfected = false
            for (infectedComputer in previousInfectedList) {
                if (computer in networkSimulator.network.adjacencyMatrix[infectedComputer]) {
                    isAdjacentToInfected = true
                }
            }
            if (!isAdjacentToInfected) {
                assertFalse(networkSimulator.getInfectedComputersList().contains(computer))
            }
        }
    }

    // with the absolute correctness (function checkStep) checking, we give defined numbers as a
    // generator of random numbers to know exactly which computers will be infected and which will not

    @Test
    fun nextTurn_oneUninfected() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/oneUninfected.json").readText()
        )
        val networkSimulator = NetworkSimulator(network, DefinedNumbers(doubleArrayOf(0.9)))
        checkStep(networkSimulator)
        assertFalse(networkSimulator.getInfectedComputersList().contains(1))
        // generator returned "0.9" both times and, according to it, 1 computer will not infect
    }

    @Test
    fun nextTurn_oneInfected() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/oneInfected.json").readText()
        )
        val networkSimulator = NetworkSimulator(network, DefinedNumbers(doubleArrayOf(0.1, 0.9, 0.4, 0.8)))
        networkSimulator.nextTurn()
        checkStep(networkSimulator)
        assertEquals(listOf(0, 2, 4), networkSimulator.getInfectedComputersList())
        // 1 and 3 computer will not infect, 0 and 2 will. And 4 was in the start
    }

    @Test
    fun nextTurn_complicatedGraph() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/complicatedGraph.json").readText()
        )
        val networkSimulator = NetworkSimulator(network, DefinedNumbers(doubleArrayOf(0.1, 0.3, 0.2)))
        networkSimulator.nextTurn()
        checkStep(networkSimulator)
        assertEquals(listOf(0, 1, 2, 3, 4), networkSimulator.getInfectedComputersList())
        // all will be infected
    }

    @Test
    fun nextTurn_graphIsCycle() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/graphIsCycle.json").readText()
        )
        val networkSimulator = NetworkSimulator(network, DefinedNumbers(doubleArrayOf(0.8, 0.9, 0.6)))
        networkSimulator.nextTurn()
        checkStep(networkSimulator)
        assertEquals(listOf(1, 2, 4), networkSimulator.getInfectedComputersList())
        // only 2 will be infected, 1 and 4 already infected
    }

    @Test
    fun nextTurn_completeGraph() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/completeGraph.json").readText()
        )
        val networkSimulator = NetworkSimulator(network, DefinedNumbers(doubleArrayOf(0.4, 0.3, 0.2)))
        networkSimulator.nextTurn()
        checkStep(networkSimulator)
        assertEquals(listOf(0, 1, 2, 3, 4), networkSimulator.getInfectedComputersList())
        // all will be infected
    }
}

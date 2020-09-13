package homeworks.homework1.task1

import kotlinx.serialization.json.Json
import org.junit.jupiter.api.Test
import org.junit.jupiter.api.Assertions.*
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
        val networkSimulator = NetworkSimulator(network)
        networkSimulator.nextTurn()
        assertEquals(listOf<Int>(), networkSimulator.getInfectedComputersList())
    }

    @Test
    fun getInfectedComputersList_emptyNetwork() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/empty.json").readText()
        )
        val networkSimulator = NetworkSimulator(network)
        assertEquals(listOf<Int>(), networkSimulator.getInfectedComputersList())
    }

    @Test
    fun nextTurn_allInfected() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/allInfected.json").readText()
        )
        val networkSimulator = NetworkSimulator(network)
        networkSimulator.nextTurn()
        assertEquals(listOf(0, 1, 2, 3, 4), networkSimulator.getInfectedComputersList())
    }

    @Test
    fun getInfectedComputersList_allInfected() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/allInfected.json").readText()
        )
        val networkSimulator = NetworkSimulator(network)
        assertEquals(listOf(0, 1, 2, 3, 4), networkSimulator.getInfectedComputersList())
    }

    @Test
    fun nextTurn_noInfected() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/noInfected.json").readText()
        )
        val networkSimulator = NetworkSimulator(network)
        networkSimulator.nextTurn()
        assertEquals(listOf<Int>(), networkSimulator.getInfectedComputersList())
    }

    @Test
    fun getInfectedComputersList_noInfected() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/noInfected.json").readText()
        )
        val networkSimulator = NetworkSimulator(network)
        assertEquals(listOf<Int>(), networkSimulator.getInfectedComputersList())
    }

    @Test
    fun nextTurn_complicatedGraphProbability100() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/complicatedGraphProbability100.json").readText()
        )
        val networkSimulator = NetworkSimulator(network)
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
        val networkSimulator = NetworkSimulator(network)
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
        val networkSimulator = NetworkSimulator(network)
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
        val networkSimulator = NetworkSimulator(network)
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
        val networkSimulator = NetworkSimulator(network)
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
        val networkSimulator = NetworkSimulator(network)
        networkSimulator.nextTurn()
        for (number in 0..2) {
            assert(networkSimulator.getInfectedComputersList().contains(number))
        }
    }
}

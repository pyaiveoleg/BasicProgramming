package homeworks.homework1.task1

import kotlinx.serialization.json.Json
import org.junit.jupiter.api.Test
import org.junit.jupiter.api.Assertions.*
import java.io.File

internal class NetworkSimulatorTest {
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
        assertEquals(listOf<Int>(0, 1, 2, 3, 4), networkSimulator.getInfectedComputersList())
    }

    @Test
    fun getInfectedComputersList_allInfected() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/allInfected.json").readText()
        )
        val networkSimulator = NetworkSimulator(network)
        assertEquals(listOf<Int>(0, 1, 2, 3, 4), networkSimulator.getInfectedComputersList())
    }

    @Test
    fun nextTurn_noInfected() {
        val network = Json.decodeFromString(
            Network.serializer(),
            File("./src/test/resources/homeworks/homework1/task1/noInfected.json").readText()
        )
        val networkSimulator = NetworkSimulator(network)
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
}

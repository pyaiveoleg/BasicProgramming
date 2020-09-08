package homeworks.homework1.task1

import kotlinx.serialization.Serializable
import kotlinx.serialization.json.Json
import java.io.File

@Serializable
data class Computer(var isInfected: Boolean, val connected: IntArray, val OS: OperatingSystem)

@Serializable
data class Network(val size: Int, val computers: Array<Computer>)

fun main() {
    val network = Json.decodeFromString(
        Network.serializer(),
        File("./src/main/resources/homeworks/homework1/task1/input.json").readText()
    )
    val networkSimulator = NetworkSimulator(network)

    val scan = java.util.Scanner(System.`in`)
    println("Please, write down quantity of iterations in infection process: ")
    val iterations = scan.nextInt()

    for (i in 1..iterations) {
        println("Iteration: $i")
        networkSimulator.nextTurn()
        print("Infected computers numbers: ${networkSimulator.getInfectedComputersList()}")
    }
}

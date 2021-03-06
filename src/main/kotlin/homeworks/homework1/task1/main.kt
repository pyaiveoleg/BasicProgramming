package homeworks.homework1.task1

import kotlinx.serialization.Serializable
import kotlinx.serialization.json.Json
import java.io.File

@Serializable
data class Computer(var isInfected: Boolean, val operatingSystem: String)

@Serializable
data class Network(
    val size: Int,
    val computers: Array<Computer>,
    val adjacencyMatrix: Array<IntArray>,
    val probabilitiesOfInfection: Map<String, Double>
)

fun main() {
    val pathToConfig = "./src/main/resources/homeworks/homework1/task1/input.json"
    println("Config will be imported from $pathToConfig")
    val network = Json.decodeFromString(
        Network.serializer(),
        File(pathToConfig).readText()
    )
    val networkSimulator = NetworkSimulator(network, ActualRandom())

    val scan = java.util.Scanner(System.`in`)
    println("Please, write down quantity of iterations in infection process: ")
    val iterations = scan.nextInt()

    for (i in 1..iterations) {
        println("Iteration: $i")
        networkSimulator.nextTurn()
        println("Infected computers numbers: ${networkSimulator.getInfectedComputersList()}")
    }
}

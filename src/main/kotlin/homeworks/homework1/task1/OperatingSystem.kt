package homeworks.homework1.task1

object ProbabilityOfInfection {
    const val P_WINDOWS = 0.3
    const val P_LINUX = 0.1
    const val P_MACOS = 0.2
}

enum class OperatingSystem(val probabilityOfInfection: Double) {
    Windows(ProbabilityOfInfection.P_WINDOWS),
    Linux(ProbabilityOfInfection.P_LINUX),
    MacOs(ProbabilityOfInfection.P_MACOS)
}

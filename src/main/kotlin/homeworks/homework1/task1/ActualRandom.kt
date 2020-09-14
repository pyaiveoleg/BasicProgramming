package homeworks.homework1.task1

import kotlin.random.Random

class ActualRandom: RandomGenerator {
    override fun generateRandomDouble(): Double {
        return Random.nextDouble(0.0, 1.0)
    }
}

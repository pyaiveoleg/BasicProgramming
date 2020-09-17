package homeworks.homework1.task1

import kotlin.random.Random

class ActualRandom : RandomProbabilityGenerator {
    override fun generateProbability(): Double {
        return Random.nextDouble(0.0, 1.0)
    }
}

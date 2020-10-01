package homeworks.homework3.task1

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class ParkingInfoTest {
    companion object Config {
        const val CAPACITY = 1000
        const val QUANTITY_OF_THREADS = 100
    }

    @Test
    fun addCar_capacityIsZero() {
        val parking = ParkingInfo(0)
        assertFalse(parking.addCar())
    }

    @Test
    fun addCar_allSpaceOccupied() {
        val parking = ParkingInfo(CAPACITY)
        for (i in 1..CAPACITY) {
            parking.addCar()
        }
        assertFalse(parking.addCar())
    }

    @Test
    fun addCar_someSpaceFree() {
        val parking = ParkingInfo(CAPACITY)
        for (i in 1..CAPACITY / 2) {
            parking.addCar()
        }
        assert(parking.addCar())
    }

    @Test
    fun addCar_manyThreadsAllRight() {
        val parking = ParkingInfo(CAPACITY)

        val arrayOfThreads = Array(QUANTITY_OF_THREADS) {
            Thread {
                for (i in 1..(CAPACITY / QUANTITY_OF_THREADS) / 2) {
                    parking.addCar()
                }
            }
        }

        arrayOfThreads.forEach { it.start() }
        arrayOfThreads.forEach { it.join() }

        assertEquals(parking.getOccupiedSpace(), CAPACITY / 2)
    }

    @Test
    fun addCar_manyThreadsParkingOverflow() {
        val parking = ParkingInfo(CAPACITY)

        val arrayOfThreads = Array(QUANTITY_OF_THREADS) {
            Thread {
                for (i in 1..CAPACITY) {
                    parking.addCar()
                }
            }
        }

        arrayOfThreads.forEach { it.start() }
        arrayOfThreads.forEach { it.join() }

        assertEquals(parking.getOccupiedSpace(), CAPACITY)
    }

    @Test
    fun removeCar_emptyParking() {
        val parking = ParkingInfo(1)
        assertFalse(parking.removeCar())
    }

    @Test
    fun removeCar_areCars() {
        val parking = ParkingInfo(1)
        parking.addCar()
        assert(parking.removeCar())
    }

    @Test
    fun removeCar_manyTreadsAllRight() {
        val parking = ParkingInfo(CAPACITY)

        for (i in 1.. CAPACITY) {
            parking.addCar()
        }

        val arrayOfThreads = Array(QUANTITY_OF_THREADS) {
            Thread {
                for (i in 1..(CAPACITY / QUANTITY_OF_THREADS) / 2) {
                    parking.removeCar()
                }
            }
        }

        arrayOfThreads.forEach { it.start() }
        arrayOfThreads.forEach { it.join() }

        assertEquals(parking.getOccupiedSpace(), CAPACITY / 2)
    }

    @Test
    fun removeCar_manyThreadsParkingOverflow() {
        val parking = ParkingInfo(CAPACITY)

        for (i in 1.. 2 * CAPACITY) {
            parking.addCar()
        }

        val arrayOfThreads = Array(QUANTITY_OF_THREADS) {
            Thread {
                for (i in 1.. 2 * CAPACITY) {
                    parking.removeCar()
                }
            }
        }

        arrayOfThreads.forEach { it.start() }
        arrayOfThreads.forEach { it.join() }

        assertEquals(parking.getOccupiedSpace(), 0)
    }

    @Test
    fun getOccupiedSpace_emptyParking() {
        val parking = ParkingInfo(CAPACITY)
        assertEquals(0, parking.getOccupiedSpace())
    }

    @Test
    fun getOccupiedSpace_allSpaceOccupied() {
        val parking = ParkingInfo(CAPACITY)

        for (i in 1..CAPACITY) {
            parking.addCar()
        }

        assertEquals(CAPACITY, parking.getOccupiedSpace())
    }

    @Test
    fun getOccupiedSpace_parkingOverflow() {
        val parking = ParkingInfo(CAPACITY)

        for (i in 1..2 * CAPACITY) {
            parking.addCar()
        }

        assertEquals(CAPACITY, parking.getOccupiedSpace())
    }
}

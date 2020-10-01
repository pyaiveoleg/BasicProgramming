package homeworks.homework3.task1

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class ParkingInfoAutomatTest {
    @Test
    fun addCar_oneAutomat() {
        val parking = ParkingInfo(2)
        val firstAutomat = ParkingInfoAutomat(parking)

        firstAutomat.addCar()
        assertEquals(firstAutomat.getOccupiedSpace(), 1)
    }

    @Test
    fun addCar_twoAutomatsCheckFirst() {
        val parking = ParkingInfo(2)
        val firstAutomat = ParkingInfoAutomat(parking)
        val secondAutomat = ParkingInfoAutomat(parking)

        firstAutomat.addCar()
        secondAutomat.addCar()
        assertEquals(firstAutomat.getOccupiedSpace(), 2)
    }

    @Test
    fun addCar_twoAutomatsCheckSecond() {
        val parking = ParkingInfo(2)
        val firstAutomat = ParkingInfoAutomat(parking)
        val secondAutomat = ParkingInfoAutomat(parking)

        firstAutomat.addCar()
        secondAutomat.addCar()
        assertEquals(secondAutomat.getOccupiedSpace(), 2)
    }

    @Test
    fun addCar_manyAutomats() {
        val capacity = 10
        val parking = ParkingInfo(capacity)
        val automatsList = List(capacity) { ParkingInfoAutomat(parking) }
        for (automat in automatsList) {
            automat.addCar()
        }

        assertEquals(parking.getOccupiedSpace(), capacity)
    }

    @Test
    fun removeCar_oneAutomat() {
        val parking = ParkingInfo(2)
        val firstAutomat = ParkingInfoAutomat(parking)

        firstAutomat.addCar()
        firstAutomat.removeCar()
        assertEquals(firstAutomat.getOccupiedSpace(), 0)
    }

    @Test
    fun removeCar_twoAutomatsCheckFirst() {
        val parking = ParkingInfo(2)
        val firstAutomat = ParkingInfoAutomat(parking)
        val secondAutomat = ParkingInfoAutomat(parking)

        firstAutomat.addCar()
        secondAutomat.removeCar()
        assertEquals(firstAutomat.getOccupiedSpace(), 0)
    }

    @Test
    fun removeCar_twoAutomatsCheckSecond() {
        val parking = ParkingInfo(2)
        val firstAutomat = ParkingInfoAutomat(parking)
        val secondAutomat = ParkingInfoAutomat(parking)

        firstAutomat.addCar()
        secondAutomat.removeCar()
        assertEquals(secondAutomat.getOccupiedSpace(), 0)
    }

    @Test
    fun removeCar_manyAutomats() {
        val capacity = 10
        val parking = ParkingInfo(capacity)
        val automatsList = List(capacity) { ParkingInfoAutomat(parking) }
        for (automat in automatsList) {
            automat.addCar()
        }

        automatsList[0].removeCar()

        assertEquals(automatsList[capacity - 1].getOccupiedSpace(), capacity - 1)
    }
}

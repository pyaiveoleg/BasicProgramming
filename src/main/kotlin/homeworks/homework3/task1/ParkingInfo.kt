package homeworks.homework3.task1

import java.util.concurrent.atomic.AtomicInteger

class ParkingInfo(private val capacity: Int) {
    private val occupiedSpace = AtomicInteger(0)

    // returns whether car was added or all space is already occupied
    fun addCar(): Boolean {
        return occupiedSpace.getAndUpdate { value -> if (value < capacity) value + 1 else value } < capacity
    }

    // returns whether car was removed or there are already 0 cars
    fun removeCar(): Boolean {
        return occupiedSpace.getAndUpdate { value -> if (value > 0) value - 1 else value } > 0
    }

    fun getOccupiedSpace(): Int {
        return occupiedSpace.get()
    }
}

package homeworks.homework3.task1

class RequestToParking(private val parking: ParkingInfo) {
    // actually there are requests using API, but in our simple case there are only calls of methods
    fun sendAddCarRequest(): Boolean {
        var result = true
        val thread = Thread {
            result = parking.addCar()
        }
        thread.run()
        thread.join()
        return result
    }

    fun sendRemoveCarRequest(): Boolean {
        var result = true
        val thread = Thread {
            result = parking.removeCar()
        }
        thread.run()
        thread.join()
        return result
    }

    fun sendGetOccupiedSpaceRequest(): Int {
        var result = 0
        val thread = Thread {
            result = parking.getOccupiedSpace()
        }
        thread.run()
        thread.join()
        return result
    }
}

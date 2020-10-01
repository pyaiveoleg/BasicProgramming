package homeworks.homework3.task1

class ParkingInfoAutomat(parking: ParkingInfo) {
    private val requestToParking = RequestToParking(parking)

    // returns whether car was added or all space is already occupied
    fun addCar(): Boolean {
        return requestToParking.sendAddCarRequest()
    }

    // returns whether car was removed or there are already 0 cars
    fun removeCar(): Boolean {
        return requestToParking.sendRemoveCarRequest()
    }

    fun getOccupiedSpace(): Int {
        return requestToParking.sendGetOccupiedSpaceRequest()
    }
}

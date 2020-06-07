package homeworks.homework7.task2

class Queue {
    private var data: String? = null
    fun set(value: String) {
        while (true) {
            synchronized(this) {
                if (data == null) {
                    data = value
                    return
                }
            }
            Thread.sleep(1000)
        }
    }

    fun get(): String? {
        while (true) {
            synchronized(this) {
                if (data != null) {
                    val result = data
                    data = null
                    return result
                }
            }
            Thread.sleep(1000)
        }
    }
}

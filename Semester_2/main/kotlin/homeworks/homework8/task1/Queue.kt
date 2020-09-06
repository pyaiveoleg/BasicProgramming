package homeworks.homework7.task2

class Queue {
    companion object Config {
        private const val delay: Long = 1000
    }

    private var data: String? = null
    fun set(value: String) {
        while (true) {
            synchronized(this) {
                if (data == null) {
                    data = value
                    return
                }
            }
            Thread.sleep(delay)
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
            Thread.sleep(delay)
        }
    }
}

package activations

import kotlin.math.exp

class Sigmoid : Activation() {
    override fun activate(x: Double): Double {
        return 1.0 / (1 + exp(-x))
    }

    override fun derivative(x: Double): Double {
        val a = activate(x)
        return a * (1 - a)
    }
}
package activations

abstract class Activation {
    abstract fun activate(x: Double): Double

    abstract fun derivative(x: Double): Double
}
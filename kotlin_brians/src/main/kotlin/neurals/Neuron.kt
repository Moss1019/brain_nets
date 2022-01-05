package neurals

abstract class Neuron(val layerIndex: Int, val index: Int) {
    var value: Double = 0.0

    abstract fun activate(): Double
}
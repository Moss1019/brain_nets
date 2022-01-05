package neurals

import activations.Activation

class OutputNeuron(layerIndex: Int, index: Int, activation: Activation) : WorkingNeuron(layerIndex, index, activation) {
    fun calculateDelta(expectedValue: Double) {
        val difference: Double = expectedValue - value
        val derivative: Double = activation.derivative(netInput)
        delta = difference * derivative
    }
}
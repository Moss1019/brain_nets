package neurals

import activations.Activation

class HiddenNeuron(layerIndex: Int, index: Int, activation: Activation) : WorkingNeuron(layerIndex, index, activation) {
    fun calculateDelta(nextLayer: List<WorkingNeuron>) {
        var s: Double = 0.0
        for (n in nextLayer) {
            s += n.delta * n.connections[index].weight
        }
        val derivative = activation.derivative(netInput)
        delta = s * derivative
    }
}
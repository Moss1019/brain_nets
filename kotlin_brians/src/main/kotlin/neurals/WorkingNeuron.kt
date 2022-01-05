package neurals

import activations.Activation

abstract class WorkingNeuron(layerIndex: Int, index: Int, protected val activation: Activation)
    :Neuron(layerIndex, index) {
    var delta: Double = 0.0
    var netInput: Double = 0.0

    private val eta: Double = 1.0

    lateinit var connections: List<Connection>

    override fun activate(): Double {
        var s = 0.0
        for (con in connections) {
            s += con.activate()
        }
        netInput = s
        value = activation.activate(s)
        return value
    }

    fun applyDelta() {
        for(c in connections) {
            val adjustment: Double = eta * delta * c.inputNeuron.value
            c.adjustWeight(adjustment)
        }
    }
}
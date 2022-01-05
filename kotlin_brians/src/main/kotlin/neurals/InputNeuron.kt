package neurals

class InputNeuron(layerIndex: Int, index: Int) : Neuron(layerIndex, index) {
    override fun activate(): Double {
        return value
    }
}
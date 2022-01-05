package neurals

class BiasNeuron(layerIndex: Int, value: Double) : Neuron(layerIndex, -1) {
    init {
        this.value = value
    }

    override fun activate(): Double {
        return value
    }
}
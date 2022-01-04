
class BiasNeuron : Neuron {
    init(layerIndex: Int, index: Int, value: Double) {
        super.init(layerIndex: layerIndex, index: index)
        self.value = value
    }
}

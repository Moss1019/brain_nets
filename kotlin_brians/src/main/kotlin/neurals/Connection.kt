package neurals

class Connection(val inputNeuron: Neuron) {
    var weight: Double = (Math.random() - 0.5) * 2.0

    fun activate(): Double {
        return inputNeuron.activate() * weight
    }

    fun adjustWeight(adjustment: Double) {
        weight += adjustment
    }
}
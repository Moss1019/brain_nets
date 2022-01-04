
class Connection {
    private let inputNeuron: Neuron
    
    private var weight: Double = Double.random(in: 0...1)
    
    init (inputNeuron: Neuron) {
        self.inputNeuron = inputNeuron
    }
    
    public func getInputNeuron() -> Neuron {
        return inputNeuron
    }
    
    public func getWeight() -> Double {
        return weight
    }
    
    public func adjustWeight(delta: Double) {
        weight += delta
    }
}


class WorkingNeuron : Neuron {
    private let eta: Double = 1.0
    
    internal var netInput: Double = 0.0
    internal var connections: [Connection] = []
    internal var activation: Activation
    
    init(layerIndex: Int, index: Int, activation: Activation) {
        self.activation = activation
        super.init(layerIndex: layerIndex, index: index)
    }
    
    public func setConnections(connections: [Connection]) {
        self.connections = connections
    }
    
    public func getConnection(index: Int) -> Connection {
        return connections[index]
    }
    
    public func applyDelta() {
        for con in connections {
            let adjustment = eta * delta * con.getInputNeuron().getValue()
            con.adjustWeight(delta: adjustment)
        }
    }
    
    public override func activate() -> Double {
        var s = 0.0
        for con in connections {
            s += con.getInputNeuron().activate() * con.getWeight()
        }
        netInput = s
        value = activation.activate(x: s)
        return value
    }
}

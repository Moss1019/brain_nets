
import Foundation

class NeuralNet {
    private let numInput: Int
    private let numHiddenLayers: Int
    private let numOutput: Int
    private let hiddenLayerCounts: [Int]
    
    private var input: [InputNeuron] = []
    private var hidden: [[HiddenNeuron]] = []
    private var output: [OutputNeuron] = []
    
    init (topology: [Int]) {
        let lastIndex = topology.count - 1
        numInput = topology[0]
        numHiddenLayers = lastIndex - 1
        numOutput = topology[lastIndex]
        if numHiddenLayers > 0 {
            hiddenLayerCounts = Array(topology[1...numHiddenLayers])
        } else {
            hiddenLayerCounts = []
        }
        setup()
    }
    
    private func setup() {
        for i in 0..<numInput {
            input.append(InputNeuron(layerIndex: 0, index: i))
        }
        for i in 0..<numHiddenLayers {
            var layer: [HiddenNeuron] = []
            for j in 0..<hiddenLayerCounts[i] {
                layer.append(HiddenNeuron(layerIndex: i + 1, index: j, activation: Sigmoid()))
            }
            hidden.append(layer)
        }
        for i in 0..<numOutput {
            output.append(OutputNeuron(layerIndex: numHiddenLayers, index: i, activation: Sigmoid()))
        }
        
        if numHiddenLayers > 0 {
            for o in output {
                var connections: [Connection] = []
                for h in hidden[numHiddenLayers - 1] {
                    connections.append(Connection(inputNeuron: h))
                }
                connections.append(Connection(inputNeuron: BiasNeuron(layerIndex: 0, index: -1, value: 1.0)))
                o.setConnections(connections: connections)
            }
            
            for i in 1..<numHiddenLayers {
                for h1 in hidden[i] {
                    var connections: [Connection] = []
                    for h2 in hidden[i - 1] {
                        connections.append(Connection(inputNeuron: h2))
                    }
                    connections.append(Connection(inputNeuron: BiasNeuron(layerIndex: i, index: -1, value: 1.0)))
                    h1.setConnections(connections: connections)
                }
            }
            
            for h in hidden[0] {
                var connections: [Connection] = []
                for i in input {
                    connections.append(Connection(inputNeuron: i))
                }
                connections.append(Connection(inputNeuron: BiasNeuron(layerIndex: numHiddenLayers - 1, index: -1, value: 1.0)))
                h.setConnections(connections: connections)
            }
        } else {
            for o in output {
                var connections: [Connection] = []
                for i in input {
                    connections.append(Connection(inputNeuron: i))
                }
                connections.append(Connection(inputNeuron: BiasNeuron(layerIndex: 1, index: -1, value: 1.0)))
                o.setConnections(connections: connections)
            }
            
        }
    }
    
    public func train(input: [[Double]], expected: [[Double]], iterations: Int) {
        for _ in 0..<iterations {
            for i in 0..<input.count {
                let ins = input[i]
                let exp = expected[i]
                
                let p = predict(input: ins)
                for j in 0..<exp.count {
                    output[j].calculateDelta(expectedValue: exp[j])
                }
                for j in stride(from: numHiddenLayers - 1, through: 0, by: -1) {
                    for h in hidden[j] {
                        h.calculateDelta(nextLayer: j == numHiddenLayers - 1 ? output : hidden[j + 1])
                    }
                }
                
                for l in hidden {
                    for h in l {
                        h.applyDelta()
                    }
                }
                for o in output {
                    o.applyDelta()
                }
            }
        }
    }
    
    public func predict(input: [Double]) -> [Double] {
        for i in 0..<input.count {
            self.input[i].setValue(value: input[i])
        }
        var output: [Double] = []
        for o in self.output {
            output.append(o.activate())
        }
        return output
    }
    
    
}

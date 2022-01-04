
class Neuron {
    internal let layerIndex: Int
    internal let index: Int
    
    internal var value: Double = 0.0
    internal var delta: Double = 0.0
    
    public var description: String { return "L\(layerIndex), #\(index): \(value)" }
    
    init(layerIndex: Int, index: Int) {
        self.layerIndex = layerIndex
        self.index = index
    }
    
    public func getValue() -> Double {
        return value
    }
    
    public func getDelta() -> Double {
        return delta
    }
    
    public func activate() -> Double {
        return value
    }
}

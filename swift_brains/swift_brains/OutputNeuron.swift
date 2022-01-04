
class OutputNeuron : WorkingNeuron {
    public func calculateDelta(expectedValue: Double) {
        let derivative = activation.derivative(x: netInput)
        let difference = expectedValue - value
        delta = derivative * difference
    }
}


class HiddenNeuron : WorkingNeuron {
    public func calculateDelta(nextLayer: [WorkingNeuron]) {
        var s = 0.0
        for n in nextLayer {
            s += n.getDelta() * n.getConnection(index: index).getWeight()
        }
        delta = activation.derivative(x: netInput) * s
    }
}

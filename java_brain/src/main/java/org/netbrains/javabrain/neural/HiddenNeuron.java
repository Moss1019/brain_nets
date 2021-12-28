package org.netbrains.javabrain.neural;

import org.netbrains.javabrain.activation.Activation;

import java.util.List;

public class HiddenNeuron extends WorkingNeuron {
    public HiddenNeuron(int layerIndex, int index, Activation activation) {
        super(layerIndex, index, activation);
    }

    public void calculateDelta(List<WorkingNeuron> nextLayer) {
        double s = 0.0;
        for(WorkingNeuron n : nextLayer) {
            s += n.getDelta() * n.get(index).getWeight();
        }
        double derivative = activation.derivative(netInput);
        delta = derivative * s;
    }
}

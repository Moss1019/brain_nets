package org.netbrains.javabrain.neural;

import org.netbrains.javabrain.activation.Activation;

public class OutputNeuron extends WorkingNeuron {
    public OutputNeuron(int layerIndex, int index, Activation activation) {
        super(layerIndex, index, activation);
    }

    public void calculateDelta(double expectedValue) {
        double derivative = activation.derivative(netInput);
        double difference = expectedValue - value;
        delta = derivative * difference;
    }
}

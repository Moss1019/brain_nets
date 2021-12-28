package org.netbrains.javabrain.neural;

public class InputNeuron extends Neuron {
    public InputNeuron(int layerIndex, int index) {
        super(layerIndex, index);
    }

    public void setValue(double value) {
        this.value = value;
    }

    @Override
    public double activate() {
        return value;
    }
}

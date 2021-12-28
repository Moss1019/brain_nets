package org.netbrains.javabrain.neural;

public class BiasNeuron extends Neuron {
    public BiasNeuron(int layerIndex, int index, double value) {
        super(layerIndex, index);
        this.value = value;
    }

    @Override
    public double activate() {
        return value;
    }
}

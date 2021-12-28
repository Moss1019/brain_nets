package org.netbrains.javabrain.neural;

public class Connection {
    private double weight;
    private final Neuron inputNeuron;

    public Connection(Neuron inputNeuron) {
        this.inputNeuron = inputNeuron;
        weight = (Math.random() -0.5) * 2.0;
    }

    public double getWeight() {
        return weight;
    }

    public Neuron getInputNeuron() {
        return inputNeuron;
    }

    public double activate() {
        return inputNeuron.activate() * weight;
    }

    public void adjustWeight(double delta) {
        weight += delta;
    }
}

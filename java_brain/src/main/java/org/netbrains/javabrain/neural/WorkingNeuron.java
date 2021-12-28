package org.netbrains.javabrain.neural;

import org.netbrains.javabrain.activation.Activation;

public abstract class WorkingNeuron extends Neuron {
    protected final Activation activation;

    public WorkingNeuron(int layerIndex, int index, Activation activation) {
        super(layerIndex, index);
        this.activation = activation;
    }

    public void applyDelta() {
        for(Connection c : connections) {
            double adjustment = eta * delta * c.getInputNeuron().getValue();
            c.adjustWeight(adjustment);
        }
    }

    @Override
    public double activate() {
        double s = 0.0;
        for(Connection con : connections) {
            s += con.activate();
        }
        netInput = s;
        value = activation.activate(s);
        return value;
    }
}

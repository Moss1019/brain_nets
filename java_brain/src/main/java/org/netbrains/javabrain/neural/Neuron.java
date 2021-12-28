package org.netbrains.javabrain.neural;

import java.util.List;

public abstract class Neuron {
    protected static final double eta = 0.5;

    protected int layerIndex;
    protected int index;
    protected double value;
    protected double netInput;
    protected double delta;
    protected List<Connection> connections;

    public Neuron(int layerIndex, int index) {
        this.layerIndex = layerIndex;
        this.index = index;
        value = 0.0;
        delta = 0.0;
    }

    public double getValue() {
        return value;
    }

    public double getDelta() {
        return delta;
    }

    public List<Connection> getConnections() {
        return connections;
    }

    public Connection get(int index) {
        return connections.get(index);
    }

    public void setConnections(List<Connection> connections) {
        this.connections = connections;
    }

    public abstract double activate();
}

package org.netbrains.javabrain.activation;

public abstract class Activation {
    public abstract double activate(double x);

    public abstract double derivative(double x);
}

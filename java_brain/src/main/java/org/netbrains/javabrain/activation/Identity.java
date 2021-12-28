package org.netbrains.javabrain.activation;

public class Identity extends Activation {
    @Override
    public double activate(double x) {
        return x;
    }

    @Override
    public double derivative(double x) {
        return 1.0;
    }
}

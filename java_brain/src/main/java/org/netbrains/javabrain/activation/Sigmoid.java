package org.netbrains.javabrain.activation;

public class Sigmoid extends Activation {
    @Override
    public double activate(double x) {
        return 1.0 / (1 + Math.pow(Math.E, -x));
    }

    @Override
    public double derivative(double x) {
        double val = activate(x);
        return val * (1 - val);
    }
}

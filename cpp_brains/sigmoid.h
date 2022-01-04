#ifndef SIGMOID_H
#define SIGMOID_H

#include "activation.h"

class Sigmoid : public Activation
{
public:
    double activate(double x);

    double derivative(double x);

private:
    const double e = 2.718;
};

#endif // SIGMOID_H

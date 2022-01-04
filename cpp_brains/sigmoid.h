#ifndef SIGMOID_H
#define SIGMOID_H

#include "activation.h"

class Sigmoid : public Activation
{
public:
    ~Sigmoid();

    double activate(double x) const;

    double derivative(double x) const;

private:
};

#endif // SIGMOID_H

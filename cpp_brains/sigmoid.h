#ifndef SIGMOID_H
#define SIGMOID_H

#include "activation.h"

class Sigmoid : public Activation
{
public:
    double activate(double x) const;

    double derivative(double x) const;
};

#endif // SIGMOID_H

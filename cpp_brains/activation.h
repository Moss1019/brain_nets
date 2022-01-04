#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "globals.h"

class Activation
{
public:
    virtual ~Activation() = 0;

    virtual double activate(double x) const = 0;

    virtual double derivative(double x) const = 0;
};

#endif // ACTIVATION_H

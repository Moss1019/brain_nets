#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "globals.h"

class Activation
{
public:
    virtual double activate(double x) = 0;

    virtual double derivative(double x) = 0;
};

#endif // ACTIVATION_H

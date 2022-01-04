#ifndef IDENTITY_H
#define IDENTITY_H

#include "globals.h"
#include "activation.h"

class Identity : public Activation
{
public:
    double activate(double x);

    double derivative(double x);
};

#endif // IDENTITY_H

#ifndef IDENTITY_H
#define IDENTITY_H

#include "globals.h"
#include "activation.h"

class Identity : public Activation
{
public:
    ~Identity();

    double activate(double x) const;

    double derivative(double x) const;
};

#endif // IDENTITY_H

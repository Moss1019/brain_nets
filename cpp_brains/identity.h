#pragma once

#include "globals.h"
#include "activation.h"

class Identity : public Activation
{
public:
    double activate(double x) const;

    double derivative(double x) const;
};

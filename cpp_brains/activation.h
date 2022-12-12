#pragma once

#include "globals.h"

class Activation
{
public:
    virtual double activate(double x) const = 0;

    virtual double derivative(double x) const = 0;
};

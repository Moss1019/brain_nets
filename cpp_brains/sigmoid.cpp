#include "sigmoid.h"

#include <cmath>

double Sigmoid::activate(double x)
{
    return 1.0 / (1 + std::pow(e, -x));
}

double Sigmoid::derivative(double x)
{
    double activated = activate(x);
    return activated * (1 - activated);
}

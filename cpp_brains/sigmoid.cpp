#include "sigmoid.h"

#include <cmath>

Sigmoid::~Sigmoid()
{

}

double Sigmoid::activate(double x) const
{
    return 1.0 / (1 + std::exp(-x));
}

double Sigmoid::derivative(double x) const
{
    double a = activate(x);
    return a * (1 - a);
}

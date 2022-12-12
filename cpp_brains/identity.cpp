#include "identity.h"

double Identity::activate(double x) const
{
    return x;
}

double Identity::derivative(double x) const
{
    return 1.0;
}

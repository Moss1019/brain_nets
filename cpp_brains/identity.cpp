#include "identity.h"

Identity::~Identity()
{

}

double Identity::activate(double x) const
{
    return x;
}

double Identity::derivative(double x) const
{
    return 1.0;
}

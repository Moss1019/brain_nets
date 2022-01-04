#ifndef NEURON_H
#define NEURON_H

#include "globals.h"
#include "connection.h"

class Neuron
{
public:
    Neuron(int layerIndex, int index);

    double getValue() const;

    virtual double activate() = 0;

protected:
    int m_layerIndex;

    int m_index;

    double m_value;
};

#endif // NEURON_H

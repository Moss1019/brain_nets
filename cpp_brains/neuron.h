#ifndef NEURON_H
#define NEURON_H

#include "globals.h"
#include "connection.h"

class Neuron
{
public:
    Neuron(int layerIndex, int index);

    virtual double activate() = 0;

    double getValue() const;

    int getLayerIndex() const;

    int getIndex() const;

protected:
    int m_layerIndex;

    int m_index;

    double m_value;
};

#endif // NEURON_H

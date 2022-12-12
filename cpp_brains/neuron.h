#pragma once

#include "globals.h"
#include "connection.h"

class Neuron
{
protected:
    int m_layerIndex{0};

    int m_index{0};

    double m_value{0.0};

public:
    Neuron(int layerIndex, int index);

    virtual double activate() = 0;

    double getValue() const;

    int getLayerIndex() const;

    int getIndex() const;
};

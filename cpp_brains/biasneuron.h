#pragma once

#include "neuron.h"

class BiasNeuron : public Neuron
{
public:
    BiasNeuron(int layerIndex, double value);

    double activate();
};

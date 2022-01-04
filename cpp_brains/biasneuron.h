#ifndef BIASNEURON_H
#define BIASNEURON_H

#include "neuron.h"

class BiasNeuron : public Neuron
{
public:
    BiasNeuron(int layerIndex, double value);

    double activate();
};

#endif // BIASNEURON_H

#ifndef INPUTNEURON_H
#define INPUTNEURON_H

#include "neuron.h"

class InputNeuron : public Neuron
{
public:
    InputNeuron(int layerIndex, int index);

    void setValue(double value);

    double activate();
};

#endif // INPUTNEURON_H

#pragma once

#include "neuron.h"

class InputNeuron : public Neuron
{
public:
    InputNeuron(int layerIndex, int index);

    InputNeuron(const InputNeuron &other) = delete;

    InputNeuron operator=(const InputNeuron &other) = delete;

    void setValue(double value);

    double activate();
};


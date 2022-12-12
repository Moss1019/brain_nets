#pragma once

#include "globals.h"

class Neuron;

class Connection
{
private:
    double m_weight{0.0};

    Neuron *m_inputNeuron{nullptr};

public:
    Connection(Neuron *inputNeuron);

    double activate() const;

    double weight() const;

    void setWeight(double weight);

    void adjustWeight(double adjustment);

    const Neuron &getNeuron() const;
};

#ifndef CONNECTION_H
#define CONNECTION_H

#include "globals.h"
#include "neuron.h"

class Connection
{
public:
    Connection(Neuron *inputNeuron);

    const Neuron *getNeuron() const;

    double getWeight() const;

    double activate() const;

    void adjustWeight(double delta);

private:
    double m_weight;

    Neuron *m_inputNeuron;
};

#endif // CONNECTION_H

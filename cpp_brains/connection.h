#ifndef CONNECTION_H
#define CONNECTION_H

#include "globals.h"
//#include "neuron.h"

class Neuron;

class Connection
{
public:
    Connection(Neuron *inputNeuron);

    double activate() const;

    double getWeight() const;

    void adjustWeight(double adjustment);

    const Neuron &getNeuron() const;

private:
    double m_weight;

    Neuron *m_inputNeuron;
};

#endif // CONNECTION_H

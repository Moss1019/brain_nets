#ifndef WORKINGNEURON_H
#define WORKINGNEURON_H

#include <vector>

#include "neuron.h"
#include "activation.h"

class WorkingNeuron : public Neuron
{
public:
    WorkingNeuron(int layerIndex, int index, Activation *activation);

    void setConnections(const std::vector<Connection> &connections);

    void applyDelta();

    double activate();

protected:
    const double eta = 1.0;

    double m_netInput;

    double m_delta;

    Activation *m_activation;

    std::vector<Connection> m_connections;
};

#endif // WORKINGNEURON_H

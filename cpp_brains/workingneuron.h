#ifndef WORKINGNEURON_H
#define WORKINGNEURON_H

#include <vector>

#include "neuron.h"
#include "activation.h"
#include "connection.h"

class WorkingNeuron : public Neuron
{
public:
    WorkingNeuron(int layerIndex, int index, Activation *activation);

    ~WorkingNeuron();

    const Connection &getConnection(int index) const;

    double getDelta() const;

    double activate();

    void applyDelta();

    void addConnection(Neuron *neuron);

protected:
    constexpr static double eta = 1.0;

    double m_netInput;

    double m_delta;

    Activation *m_activation;

    std::vector<Connection *> m_connections;
};

#endif // WORKINGNEURON_H

#pragma once

#include <vector>

#include "neuron.h"
#include "activation.h"
#include "connection.h"

class WorkingNeuron : public Neuron
{
protected:
    constexpr static double eta{1.0};

    double m_netInput{0.0};

    double m_delta{0.0};

    Activation *m_activation{nullptr};

    std::vector<Connection *> m_connections;

public:
    WorkingNeuron(int layerIndex, int index, Activation *activation);

    WorkingNeuron(const WorkingNeuron &other) = delete;

    WorkingNeuron operator=(const WorkingNeuron &other) = delete;

    ~WorkingNeuron();

    const std::vector<Connection *> &connections() const;

    const Connection &getConnection(int index) const;

    double getDelta() const;

    double activate();

    void applyDelta();

    void addConnection(Neuron *neuron);
};

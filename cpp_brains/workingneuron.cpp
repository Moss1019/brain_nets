#include "workingneuron.h"

WorkingNeuron::WorkingNeuron(int layerIndex, int index, Activation *activation)
    :Neuron(layerIndex, index), m_activation{activation}
{

}

void WorkingNeuron::setConnections(const std::vector<Connection> &connections)
{
    m_connections = connections;
}

void WorkingNeuron::applyDelta()
{
    for(auto con : m_connections)
    {
        double adjustment = eta * m_delta * con.getNeuron().getValue();
        con.adjustWeight(adjustment);
    }
}

double WorkingNeuron::activate()
{
    double s = 0.0;
    for(auto con : m_connections)
    {
        s += con.activate();
    }
    m_netInput = s;
    m_value = m_activation->activate(s);
    return m_value;
}

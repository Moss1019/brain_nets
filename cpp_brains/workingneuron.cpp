#include "workingneuron.h"

#ifdef DEBUG
#include <iostream>
#endif

WorkingNeuron::WorkingNeuron(int layerIndex, int index, Activation *activation)
    :Neuron{layerIndex, index}, m_activation{activation}
{

}

WorkingNeuron::~WorkingNeuron()
{
    for(auto ptr : m_connections)
    {
        delete ptr;
    }
}

const std::vector<Connection *> &WorkingNeuron::connections() const
{
    return m_connections;
}

const Connection &WorkingNeuron::getConnection(int index) const
{
    return *m_connections[index];
}

double WorkingNeuron::activate()
{
#ifdef DEBUG
    std::cout << "Working neuron [" << m_layerIndex << " " << m_index << "]" << std::endl;
#endif
    double s = 0.0;
    for(auto con : m_connections)
    {
        s += con->activate();
#ifdef DEBUG
        std::cout << "\t[" << con->getNeuron().getLayerIndex() << " " << con->getNeuron().getIndex() << "]" << std::endl;
        std::cout << "\t[" << con->getNeuron().getValue() << " " << con->getWeight() << "]" << std::endl;
        std::cout << "\tAdding connection to s = " << s << std::endl;
#endif
    }
    m_netInput = s;
    m_value = m_activation->activate(s);
    return m_value;
}

double WorkingNeuron::getDelta() const
{
    return m_delta;
}

void WorkingNeuron::applyDelta()
{
    for(auto con : m_connections)
    {
        double adjustment = eta * m_delta * con->getNeuron().getValue();
        con->adjustWeight(adjustment);
    }
}

void WorkingNeuron::addConnection(Neuron *neuron)
{
    m_connections.push_back(new Connection(neuron));
}

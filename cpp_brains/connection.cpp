#include "connection.h"

#include <cstdlib>

#ifdef DEBUG
#include <iostream>
#endif

Connection::Connection(Neuron *inputNeuron)
    : m_inputNeuron{inputNeuron}
{
    m_weight = std::rand() / RAND_MAX;
#ifdef DEBUG
    std::cout << "Connection " << m_weight << std::endl;
#endif
}

const Neuron *Connection::getNeuron() const
{
    return m_inputNeuron;
}

double Connection::getWeight() const
{
    return m_weight;
}

double Connection::activate() const
{
    return m_weight * m_inputNeuron->activate();
}

void Connection::adjustWeight(double delta)
{
    m_weight += delta;
}

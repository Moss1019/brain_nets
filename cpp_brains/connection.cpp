#include "connection.h"
#include "neuron.h"

#include <cstdlib>

Connection::Connection(Neuron *inputNeuron)
    :m_inputNeuron{inputNeuron}
{
    m_weight = 1.0 * std::rand() / RAND_MAX;
}

double Connection::activate() const
{
    return m_inputNeuron->activate() * m_weight;
}

double Connection::weight() const
{
    return m_weight;
}

void Connection::setWeight(double weight)
{
    m_weight = weight;
}

void Connection::adjustWeight(double adjustment)
{
    m_weight += adjustment;
}

const Neuron &Connection::getNeuron() const
{
    return *m_inputNeuron;
}

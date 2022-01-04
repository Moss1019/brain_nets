#include "biasneuron.h"

BiasNeuron::BiasNeuron(int layerIndex, double value)
    :Neuron{layerIndex, -1}
{
    m_value = value;
}

double BiasNeuron::activate()
{
    return m_value;
}

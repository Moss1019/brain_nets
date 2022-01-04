#include "neuron.h"

Neuron::Neuron(int layerIndex, int index)
    : m_layerIndex{layerIndex}, m_index{index}
{
}

double Neuron::getValue() const
{
    return m_value;
}

#include "inputneuron.h"

InputNeuron::InputNeuron(int layerIndex, int index)
    :Neuron{layerIndex, index}
{

}

void InputNeuron::setValue(double value)
{
    m_value = value;
}

double InputNeuron::activate()
{
    return m_value;
}

#include "outputneuron.h"

#ifdef TRAINING_DEBUG
#include <iostream>
#endif
#ifdef DEBUG
#include <iostream>
#endif

OutputNeuron::OutputNeuron(int layerIndex, int index, Activation *activation)
    :WorkingNeuron(layerIndex, index, activation)
{

}

void OutputNeuron::calculateDelta(double expected)
{
    double difference = expected - m_value;
    double derivative = m_activation->derivative(m_netInput);
    m_delta = derivative * difference;
#ifdef TRAINING_DEBUG
    std::cout << "delta for " << m_layerIndex << " " << m_index << " dif:" << difference << " D:" << m_delta << std::endl;
#endif
}

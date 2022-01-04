#include "hiddenneuron.h"

HiddenNeuron::HiddenNeuron(int layerIndex, int index, Activation *activation)
    :WorkingNeuron(layerIndex, index, activation)
{

}

void HiddenNeuron::calculateDelta(const std::vector<WorkingNeuron *> &nextLayer)
{
    double s = 0.0;
    for(auto n : nextLayer)
    {
        s += n->getDelta() * n->getConnection(m_index).getNeuron().getValue();
    }
    double derivative = m_activation->derivative(m_netInput);
    m_delta = derivative * s;
}

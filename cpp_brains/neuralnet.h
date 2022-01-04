#ifndef NEURALNET_H
#define NEURALNET_H

#include <vector>

#include "globals.h"
#include "sigmoid.h"
#include "biasneuron.h"
#include "inputneuron.h"
#include "hiddenneuron.h"
#include "outputneuron.h"

class NeuralNet
{
public:
    NeuralNet(const std::vector<int> &topology);

    ~NeuralNet();

    void train(const std::vector<double *> &inputs, const std::vector<double *> expected, int iterations);

    const std::vector<double> predict(double *input);

private:
    int m_numInputs;

    int m_numHiddenLayers;

    int m_numOutputs;

    Activation *m_sigmoid;

    std::vector<int> m_hiddenCounts;

    std::vector<Connection *> m_allConnections;

    std::vector<InputNeuron *> m_input;

    std::vector<std::vector<WorkingNeuron *>> m_hidden;

    std::vector<WorkingNeuron *> m_output;

    std::vector<BiasNeuron *> m_bias;

    void setup();
};

#endif // NEURALNET_H

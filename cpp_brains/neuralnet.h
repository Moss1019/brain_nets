#pragma once

#include <vector>

#include "globals.h"
#include "sigmoid.h"
#include "biasneuron.h"
#include "inputneuron.h"
#include "hiddenneuron.h"
#include "outputneuron.h"

class NeuralNet
{
private:
    int m_numInputs{0};

    int m_numHiddenLayers{0};

    int m_numOutputs{0};

    Activation *m_sigmoid{nullptr};

    std::vector<int> m_hiddenCounts;

    std::vector<Connection *> m_allConnections;

    std::vector<InputNeuron *> m_input;

    std::vector<std::vector<WorkingNeuron *>> m_hidden;

    std::vector<WorkingNeuron *> m_output;

    std::vector<BiasNeuron *> m_bias;

    void setup();

public:
    NeuralNet();

    NeuralNet(const std::vector<int> &topology);

    NeuralNet(const NeuralNet &other) = delete;

    NeuralNet operator=(const NeuralNet &other) = delete;

    ~NeuralNet();

    void train(const std::vector<std::vector<double>> &inputs, const std::vector<std::vector<double>> expected, int iterations);

    const void predict(const std::vector<double> &input, std::vector<double> &output);
};

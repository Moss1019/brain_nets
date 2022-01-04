#include "neuralnet.h"
#include "sigmoid.h"

#ifdef DEBUG
#include <iostream>
#endif

NeuralNet::NeuralNet(const std::vector<int> &topology)
{
    m_numInputs = topology[0];
    int lastIndex = topology.size() - 1;
    m_numOutputs = topology[lastIndex];
    m_numHiddenLayers = lastIndex - 1;
    for(int i = 1; i <= m_numHiddenLayers; ++i)
    {
        m_hiddenCounts.push_back(topology[i]);
    }
    m_sigmoid = new Sigmoid();
    setup();
#ifdef DEBUG
    std::cout << "inputs: " << m_numInputs << " hidden layers: " << m_numHiddenLayers << " outputs: " << m_numOutputs << std::endl << "Hidden layer counts: ";
    for(auto i : m_hiddenCounts)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
#endif
}

NeuralNet::~NeuralNet()
{
    delete m_sigmoid;
    for(auto i : m_input)
    {
        delete i;
    }
    for(auto o : m_output)
    {
        delete o;
    }
    for(auto l : m_hidden)
    {
        for(auto h : l)
        {
            delete h;
        }
    }
    for(auto b : m_bias)
    {
        delete b;
    }
}

void NeuralNet::train(const std::vector<double *> &inputs, const std::vector<double *> expected, int iterations)
{
    for(int i = 0; i < iterations; ++i)
    {
        for(int j = 0; j < inputs.size(); ++j)
        {
            double *ins = inputs[j];
            double *exd = expected[j];
            predict(ins);
            for(int k = 0; k < m_output.size(); ++k)
            {
                static_cast<OutputNeuron *>(m_output[k])->calculateDelta(exd[k]);
            }
            for(int l = m_hidden.size() - 1; l >= 0; --l)
            {
                for(int k = 0; k < m_hidden[l].size(); ++k)
                {
                    static_cast<HiddenNeuron *>(m_hidden[l][k])->calculateDelta(l == m_hidden.size() - 1 ? m_output : m_hidden[l + 1]);
                }
            }
            for(auto o : m_output)
            {
                o->applyDelta();
            }
            for(auto l : m_hidden)
            {
                for(auto h : l)
                {
                    h->applyDelta();
                }
            }
        }
    }
}

const std::vector<double> NeuralNet::predict(double *input)
{
    for(int i = 0; i < m_input.size(); ++i)
    {
        m_input[i]->setValue(input[i]);
    }
    std::vector<double> output;
#ifdef DEBUG
    std::cout << "Predicting for ";
    for(int i = 0; i < m_input.size(); ++i)
    {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
#endif
    for(auto o : m_output)
    {
        output.push_back(o->activate());
#ifdef DEBUG
        std::cout << "\tPredicted val ";
        std::cout << o->getValue() << std::endl;
#endif
    }
    return output;
}

void NeuralNet::setup()
{
    for(int i = 0; i < m_numInputs; ++i)
    {
        m_input.push_back(new InputNeuron(0, i));
    }
    for(int i = 0; i < m_numHiddenLayers; ++i)
    {
        std::vector<WorkingNeuron *> layer;
        for(int j = 0; j < m_hiddenCounts[i]; ++j)
        {
            layer.push_back(new HiddenNeuron(i + 1, j, m_sigmoid));
        }
        m_hidden.push_back(layer);
    }
    for(int i = 0; i < m_numOutputs; ++i)
    {
        m_output.push_back(new OutputNeuron(m_numHiddenLayers, i, m_sigmoid));
    }

    if(m_numHiddenLayers > 0)
    {
        for(auto o : m_output)
        {
            for(auto h : m_hidden[m_numHiddenLayers - 1])
            {
                o->addConnection(h);
#ifdef DEBUG
                std::cout << "Setting connection between output " << o->getIndex() << " and hidden " << h->getIndex() << std::endl;
#endif
            }
            BiasNeuron *b = new BiasNeuron(0, 1.0);
            m_bias.push_back(b);
            o->addConnection(b);
        }

        for(auto h : m_hidden[0])
        {
            for(auto i : m_input)
            {
                h->addConnection(i);
#ifdef DEBUG
                std::cout << "Setting connection between hidden " << h->getIndex() << " and input " << i->getIndex() << std::endl;
#endif
            }
            BiasNeuron *b = new BiasNeuron(0, 1.0);
            m_bias.push_back(b);
            h->addConnection(b);
        }

        for(int i = 0; i < m_numHiddenLayers - 1; ++i)
        {
            for(auto h1 : m_hidden[i + 1])
            {
                for(auto h2 : m_hidden[i])
                {
                    h1->addConnection(h2);
#ifdef DEBUG
                    std::cout << i << "Setting connection between hidden " << h1->getLayerIndex() << " " << h1->getIndex() << " and hidden " << h2->getLayerIndex() << " " << h2->getIndex() << std::endl;
#endif
                }
                BiasNeuron *b = new BiasNeuron(0, 1.0);
                m_bias.push_back(b);
                h1->addConnection(b);
            }
        }
    }
    else
    {
        for(auto o : m_output)
        {
            for(auto i : m_input)
            {
                o->addConnection(i);
            }
            BiasNeuron *b = new BiasNeuron(0, 1.0);
            m_bias.push_back(b);
            o->addConnection(b);
        }
    }
}

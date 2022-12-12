
#include <iostream>

#include <vector>

#define DEBUG

#include "neuralnet.h"

#include "sigmoid.h"
#include "identity.h"

int main()
{
    std::vector<int> topology;
    topology.push_back(3);
    topology.push_back(2);

    NeuralNet nn(topology);

    std::vector<std::vector<double>> inputs;
    std::vector<std::vector<double>> expected;

    Identity act1;
    Sigmoid act2;

    InputNeuron in1{0, 0};
    in1.setValue(1.0f);

    WorkingNeuron wn1{1, 0, &act2};
    wn1.addConnection(&in1);

    WorkingNeuron wn2{1, 1, &act2};
    wn1.addConnection(&in1);

    WorkingNeuron wn3{1, 1, &act2};
    wn1.addConnection(&in1);

    OutputNeuron on1{2, 0, &act2};
    on1.addConnection(&wn1);
    on1.addConnection(&wn2);
    on1.addConnection(&wn3);

    for(auto &c : wn1.connections())
    {
        c->setWeight(1.0);
    }
    for(auto &c : wn2.connections())
    {
        c->setWeight(1.0);
    }
    for(auto &c : on1.connections())
    {
        c->setWeight(1.0);
    }

    double output = on1.activate();

    std::cout << output << "\n";

    return 0;
}

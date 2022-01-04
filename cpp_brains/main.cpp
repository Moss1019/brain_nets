
#include <iostream>

#include <vector>

#include "neuralnet.h"

int main()
{
    std::vector<int> topology;
    topology.push_back(2);
    topology.push_back(2);
    topology.push_back(1);

    NeuralNet nn(topology);

    std::vector<double *> inputs;
    std::vector<double *> expected;
    for(int i = 0; i < 500; ++i)
    {
        double *ins = reinterpret_cast<double *>(std::malloc(sizeof(double) * 2));
        ins[0] = i % 3 == 0 ? 1.0 : 0.0;
        ins[1] = i % 5 == 0 ? 1.0 : 0.0;
        double *exd =  reinterpret_cast<double *>(std::malloc(sizeof(double)));
        exd[0] = i % 3 == 0 && i % 5 == 0 ? 1.0 : 0.0;
        inputs.push_back(ins);
        expected.push_back(exd);
    }
    nn.train(inputs, expected, 1000);
    for(int i = 0; i < 500; ++i)
    {
        std::free(inputs[i]);
        std::free(expected[i]);
    }

    double i[2];
    i[0] = 1.0;
    i[1] = 1.0;
    std::vector<double> o = nn.predict(i);
    for(auto l : o)
    {
        std::cout << "Val " << l << " ";
    }
    i[0] = 0.0;
    i[1] = 1.0;
    o = nn.predict(i);
    for(auto l : o)
    {
        std::cout << "Val " << l << " ";
    }
    std::cout << std::endl;

    return 0;
}

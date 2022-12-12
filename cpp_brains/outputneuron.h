#pragma once

#include "workingneuron.h"

class OutputNeuron : public WorkingNeuron
{
public:
    OutputNeuron(int layerIndex, int index, Activation *activation);

    void calculateDelta(double expected);
};


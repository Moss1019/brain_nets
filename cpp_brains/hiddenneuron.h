#pragma once

#include <vector>

#include "workingneuron.h"

class HiddenNeuron : public WorkingNeuron
{
public:
    HiddenNeuron(int layerIndex, int index, Activation *activation);

    void calculateDelta(const std::vector<WorkingNeuron *> &nextLayer);
};

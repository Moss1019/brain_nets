#ifndef OUTPUTNEURON_H
#define OUTPUTNEURON_H

#include "workingneuron.h"

class OutputNeuron : public WorkingNeuron
{
public:
    OutputNeuron(int layerIndex, int index, Activation *activation);

    void calculateDelta(double expected);
};

#endif // OUTPUTNEURON_H

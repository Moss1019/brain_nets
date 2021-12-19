
from src.neuron import Neuron


class BiasNeuron(Neuron):
    def __init__(self, layer, index, activation, bias):
        Neuron.__init__(self, layer, index, activation)
        self._value = bias

    def activate(self):
        return self._value

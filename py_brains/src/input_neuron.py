
from src.neuron import Neuron


class InputNeuron(Neuron):
    def set_value(self, value):
        self._value = value

    def activate(self):
        return self._value

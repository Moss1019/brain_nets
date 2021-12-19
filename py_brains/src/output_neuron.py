
from src.neuron import Neuron


class OutputNeuron(Neuron):
    def activate(self):
        s = 0.0
        for c in self._connections:
            s += c.activate()
        self._net_input = s
        self._value = self._activation.activate(s)
        return self._value

    def calculate_delta(self, expected):
        derivative = self._activation.derivative(self._net_input)
        difference = expected - self._value
        self._delta = derivative * difference

    def apply_deltas(self):
        for c in self._connections:
            delta_weight = Neuron._eta * self._delta * c.get_neuron().get_value()
            c.alter_weight(delta_weight)

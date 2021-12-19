
from src.neuron import Neuron


class WorkingNeuron(Neuron):
    def activate(self):
        s = 0.0
        for c in self._connections:
            s += c.activate()
        self._net_input = s
        self._value = self._activation.activate(s)
        return self._value

    def calculate_delta(self, next_layer):
        derivative = self._activation.derivative(self._net_input)
        s = 0.0
        for i in range(len(next_layer)):
            s += next_layer[i].get_delta() * next_layer[i].get_connections()[self._index].get_weight()
        self._delta = derivative * s

    def apply_deltas(self):
        for c in self._connections:
            delta_weight = Neuron._eta * self._delta * c.get_neuron().get_value()
            c.alter_weight(delta_weight)

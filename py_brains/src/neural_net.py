
from src.working_neuron import WorkingNeuron
from src.output_neuron import OutputNeuron
from src.input_neuron import InputNeuron
from src.bias_neuron import BiasNeuron
from src.connection import Connection
from src.activation import Activation

import math


def sig(net_input):
    return 1.0 / (1 + pow(math.e, -net_input))


def sig_d(net_input):
    activated = sig(net_input)
    return activated * (1 - activated)


def idn(net_input):
    return net_input


def idn_d(_):
    return 1.0


def tan_h(net_input):
    return math.tanh(net_input)


def tan_h_d(net_input):
    activated = tan_h(net_input)
    return 1 - pow(activated, 2)


class NeuralNet(object):
    def __init__(self, topology, fully_connected=True):
        self._num_inputs = topology[0]
        self._num_outputs = topology[-1]
        self._num_hidden_layers = len(topology[1:-1])
        self._num_hidden = topology[1:-1]
        self._fully_connected = fully_connected
        self._activations = [Activation(tan_h, tan_h_d), Activation(sig, sig_d)]
        self._bias = []
        self._inputs = []
        self._hidden_layers = []
        self._outputs = []
        self._setup()

    def get_layers(self):
        layers = [self._inputs + [self._bias[0]]]
        hidden_index = 1
        for h in self._hidden_layers:
            layers.append(h + [self._bias[hidden_index]])
            hidden_index += 1
        layers.append(self._outputs)
        return layers

    def add_connection(self, input_layer, input_index, output_layer, output_index):
        if input_layer == 0:
            input_neuron = self._inputs[input_index]
        else:
            input_neuron = self._hidden_layers[input_layer - 1][input_index]
        if output_layer == self._num_hidden_layers + 1:
            output_neuron = self._outputs[output_index]
        else:
            output_neuron = self._hidden_layers[output_layer - 1][output_index]
        bias_connection = output_neuron.get_connections()[-1]
        new_connections = output_neuron.get_connections()[:-1]
        new_connections.append(Connection(input_neuron))
        new_connections.append(bias_connection)
        output_neuron.set_connections(new_connections)

    def predict(self, inputs):
        for i in range(self._num_inputs):
            self._inputs[i].set_value(inputs[i])

        outs = []
        for o in self._outputs:
            outs.append(o.activate())
        return outs

    def train(self, inputs, expected, iterations=500):
        for _ in range(iterations):
            num_iterations = len(inputs)
            for iteration in range(num_iterations):

                self.predict(inputs[iteration])
                ex = expected[iteration]

                for i in range(self._num_outputs):
                    self._outputs[i].calculate_delta(ex[i])

                if self._num_hidden_layers > 0:
                    for h in self._hidden_layers[-1]:
                        h.calculate_delta(self._outputs)

                for i in range(self._num_hidden_layers - 1, 0, -1):
                    for h in self._hidden_layers[i - 1]:
                        h.calculate_delta(self._hidden_layers[i])

                for o in self._outputs:
                    o.apply_deltas()

                for hl in self._hidden_layers:
                    for h in hl:
                        h.apply_deltas()

    def _setup(self):
        for i in range(self._num_inputs):
            self._inputs.append(InputNeuron(0, i, self._activations[0]))
        self._bias.append(BiasNeuron(0, self._num_inputs, self._activations[0], 1.0))

        for i in range(self._num_hidden_layers):
            layer = []
            for j in range(self._num_hidden[i]):
                layer.append(WorkingNeuron(i + 1, j, self._activations[0]))
            self._hidden_layers.append(layer)
            self._bias.append(BiasNeuron(i + 1, self._num_hidden[i], self._activations[0], 1.0))

        for i in range(self._num_outputs):
            self._outputs.append(OutputNeuron(self._num_hidden_layers + 1, i, self._activations[0]))

        if self._num_hidden_layers > 0:
            for h in self._hidden_layers[0]:
                connections = []
                if self._fully_connected:
                    for i in self._inputs:
                        connections.append(Connection(i))
                connections.append(Connection(self._bias[0]))
                h.set_connections(connections)

            for i in range(1, self._num_hidden_layers):
                for h in self._hidden_layers[i]:
                    connections = []
                    if self._fully_connected:
                        for h_inner in self._hidden_layers[i - 1]:
                            connections.append(Connection(h_inner))
                    connections.append(Connection(self._bias[i]))
                    h.set_connections(connections)

            for o in self._outputs:
                connections = []
                if self._fully_connected:
                    for h in self._hidden_layers[-1]:
                        connections.append(Connection(h))
                connections.append(Connection(self._bias[-1]))
                o.set_connections(connections)
        else:
            for o in self._outputs:
                connections = []
                if self._fully_connected:
                    for i in self._inputs:
                        connections.append(Connection(i))
                connections.append(Connection(self._bias[-1]))
                o.set_connections(connections)

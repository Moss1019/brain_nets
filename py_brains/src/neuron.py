class Neuron(object):
    _eta = 0.01

    def __init__(self, layer, index, activation):
        self._layer = layer
        self._index = index
        self._activation = activation
        self._value = 0.0
        self._net_input = 0.0
        self._delta = 0.0
        self._connections = []

    def __str__(self):
        con_str = ' '.join(['%s' % c.get_weight() for c in self._connections])
        return '%d %d %f => %s' % (self._layer, self._index, self._value, con_str)

    def get_layer(self):
        return self._layer

    def get_index(self):
        return self._index

    def get_value(self):
        return self._value

    def get_net_input(self):
        return self._net_input

    def get_delta(self):
        return self._delta

    def get_connections(self):
        return self._connections

    def set_connections(self, connections):
        self._connections = connections

    def activate(self):
        return 0.0

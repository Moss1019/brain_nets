
from random import random


def random_m1_p1():
    return random() - 0.5


class Connection(object):
    def __init__(self, neuron, weight=random_m1_p1()):
        self._neuron = neuron
        self._weight = weight

    def __str__(self):
        return '%s %s' % (self._neuron, self._weight)

    def get_weight(self):
        return self._weight

    def get_neuron(self):
        return self._neuron

    def alter_weight(self, delta):
        self._weight += delta

    def activate(self):
        return self._neuron.activate() * self._weight

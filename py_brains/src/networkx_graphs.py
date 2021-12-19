from src.bias_neuron import BiasNeuron
from src.neural_net import NeuralNet

import networkx as nx
import matplotlib.pyplot as plt


class NetworkXGraphs(object):
    def __init__(self, neural_net):
        self._nn = neural_net

    def draw(self):
        layers = self._nn.get_layers()
        gg = nx.Graph()
        layer_index = 0
        labels = {}
        edge_label = {}
        for l in layers:
            node_index = 0
            for n in l:
                gg.add_node(str(n), pos=(layer_index, node_index))
                labels[str(n)] = round(n.get_value(), 2)
                for c in n.get_connections():
                    gg.add_edge(str(n), str(c.get_neuron()))
                    edge_label[(str(n), str(c.get_neuron()))] = round(c.get_weight(), 2)
                node_index += 1
            layer_index += 1

        pos = nx.get_node_attributes(gg, 'pos')
        plt.subplot()
        nx.draw(gg, pos, with_labels=False, node_size=750)
        nx.draw_networkx_labels(gg, pos, labels)
        nx.draw_networkx_edge_labels(gg, pos, edge_label, label_pos=0.3)
        plt.show()
        plt.pause(0.001)


if __name__ == '__main__':
    nn = NeuralNet([2, 3, 4, 2])
    nn.add_connection(1, 0, 1, 1)
    g = NetworkXGraphs(nn)
    nn.train([[1, 1]], [[1, 0]], 500)
    nn.predict([1, 1])
    g.draw()

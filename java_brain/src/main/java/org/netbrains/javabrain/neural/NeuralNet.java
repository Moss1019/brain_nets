package org.netbrains.javabrain.neural;

import org.netbrains.javabrain.activation.Identity;
import org.netbrains.javabrain.activation.Sigmoid;

import java.util.ArrayList;
import java.util.List;

public class NeuralNet {
    private final int numInputs;
    private final int numHiddenLayers;
    private final int numOutput;
    private final List<Integer> numHidden;

    private List<Neuron> input;
    private List<List<WorkingNeuron>> hidden;
    private List<WorkingNeuron> output;

    public NeuralNet(List<Integer> topology) {
        numInputs = topology.get(0);
        numOutput = topology.get(topology.size() - 1);
        numHidden = new ArrayList<>();
        for(int i = 1; i < topology.size() - 1; ++i) {
            numHidden.add(topology.get(i));
        }
        numHiddenLayers = numHidden.size();
        setup();
    }

    public List<Double> predict(List<Double> inputs) {
        for(int i = 0; i < inputs.size(); ++i) {
            ((InputNeuron)input.get(i)).setValue(inputs.get(i));
        }
        List<Double> outputs = new ArrayList<>();
        for(WorkingNeuron o : output) {
            outputs.add(o.activate());
        }
        return outputs;
    }

    public void train(List<List<Double>> inputs, List<List<Double>> expected, int iterations) {
        for(int i = 0; i < iterations; ++i) {
            for(int j = 0; j < inputs.size(); ++j) {
                List<Double> in = inputs.get(j);
                List<Double> out = expected.get(j);

                List<Double> actual = predict(in);
                for(int k = 0; k < actual.size(); ++k) {
                    ((OutputNeuron)output.get(k)).calculateDelta(out.get(k));
                }

                for(int k = hidden.size() - 1; k >= 0; --k) {
                    for(int hk = 0; hk < hidden.get(k).size(); ++hk) {
                        List<WorkingNeuron> nextLayer = output;
                        ((HiddenNeuron)hidden.get(k).get(hk)).calculateDelta(nextLayer);
                    }
                }

                for(WorkingNeuron o : output) {
                    o.applyDelta();
                }

                for(List<WorkingNeuron> hl : hidden) {
                    for(WorkingNeuron h : hl) {
                        h.applyDelta();
                    }
                }
            }
        }
    }

    private void setup() {
        input = new ArrayList<>();
        for (int i = 0; i < numInputs; ++i) {
            input.add(new InputNeuron(0, i));
        }

        output = new ArrayList<>();
        for(int i = 0; i < numOutput; ++i) {
            output.add(new OutputNeuron(numHiddenLayers + 2, i, new Sigmoid()));
        }

        hidden = new ArrayList<>();
        int layerIndex = 1;
        for(int n : numHidden) {
            List<WorkingNeuron> hidden = new ArrayList<>();
            for(int i = 0; i < n; ++i) {
                hidden.add(new HiddenNeuron(layerIndex++, i, new Sigmoid()));
            }
            this.hidden.add(hidden);
        }

        if(numHiddenLayers > 0) {
            for (WorkingNeuron o : output) {
                List<Connection> connections = new ArrayList<>();
                for (WorkingNeuron h : hidden.get(hidden.size() - 1)) {
                    connections.add(new Connection(h));
                }
                connections.add(new Connection(new BiasNeuron(-1, -1,1.0)));
                o.setConnections(connections);
            }

            for (WorkingNeuron h : hidden.get(0)) {
                List<Connection> connections = new ArrayList<>();
                for (Neuron i : input) {
                    connections.add(new Connection(i));
                }
                connections.add(new Connection(new BiasNeuron(-1, -1,1.0)));
                h.setConnections(connections);
            }

            for (int i = 1; i < numHiddenLayers; ++i) {
                for (WorkingNeuron h1 : hidden.get(i)) {
                    List<Connection> connections = new ArrayList<>();
                    for (WorkingNeuron h2 : hidden.get(i - 1)) {
                        connections.add(new Connection(h2));
                    }
                    connections.add(new Connection(new BiasNeuron(-1, -1,1.0)));
                    h1.setConnections(connections);
                }
            }
        } else {
            for (WorkingNeuron o : output) {
                List<Connection> connections = new ArrayList<>();
                for (Neuron n : input) {
                    connections.add(new Connection(n));
                }
                connections.add(new Connection(new BiasNeuron(-1, -1,1.0)));
                o.setConnections(connections);
            }
        }
    }
}

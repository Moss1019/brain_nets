using SharpBrain.Activations;
using SharpBrain.Utils;
using System;
using System.Collections.Generic;
using System.Linq;

namespace SharpBrain.Neural
{
    public class NeuralNet
    {
        private readonly ActivationStrategy strategy;
        private readonly Activation activation;

        private int numInputs;
        private int numHiddenLayers;
        private List<int> numHidden;
        private int numOutput;
        private Layer inputLayer;
        private List<Layer> hiddenLayers;
        private Layer outputLayer;
        private Neuron bias;
        private int activationIndex = -1;

        public NeuralNet(List<int> topology, ActivationStrategy strategy)
        {
            this.strategy = strategy;
            SetupTopology(topology);
            Setup();
        }

        public NeuralNet(List<int> topology, Activation activation)
        {
            this.activation = activation;
            SetupTopology(topology);
            Setup();
        }

        public List<double> Predict(List<double> input)
        {
            var index = 0;
            foreach (var n in inputLayer)
            {
                n.Value = input[index++];
            }
            var output = new List<double>();
            foreach (var n in outputLayer)
            {
                output.Add(n.Activate());
            }
            return output;
        }

        public void Train(List<List<double>> input, List<List<double>> expected, int iterations = 500)
        {
            for (int i = 0; i < iterations; ++i)
            {
                var numSamples = input.Count;
                for (int j = 0; j < numSamples; ++j)
                {
                    Predict(input[j]);
                    for (int k = 0; k < numOutput; ++k)
                    {
                        var o = outputLayer[k] as OutputNeuron;
                        o.CalculateDelta(expected[j][k]);
                    }

                    for (int k = numHiddenLayers - 1; k >= 0; --k)
                    {
                        var currentLayer = hiddenLayers[k];
                        for (int hk = 0; hk < currentLayer.Count; ++hk)
                        {
                            var h = currentLayer[hk] as HiddenNeuron;
                            h.CalculateDelta(k == numHiddenLayers - 1 ? outputLayer : hiddenLayers[k + 1]);
                        }
                    }

                    for (int k = 0; k < numOutput; ++k)
                    {
                        var o = outputLayer[k] as OutputNeuron;
                        o.ApplyDelta();
                    }

                    for (int k = numHiddenLayers - 1; k >= 0; --k)
                    {
                        var currentLayer = hiddenLayers[k];
                        for (int hk = 0; hk < currentLayer.Count; ++hk)
                        {
                            var h = currentLayer[hk] as HiddenNeuron;
                            h.ApplyDelta();
                        }
                    }
                }
            }
        }

        private void SetupTopology(List<int> topology)
        {
            int lastIndex = topology.Count - 1;
            numInputs = topology[0];
            numOutput = topology[lastIndex];
            numHiddenLayers = lastIndex - 1;
            numHidden = topology.Slice(1, numHiddenLayers);
        }

        private void Setup()
        {
            inputLayer = new Layer();
            for (int i = 0; i < numInputs; ++i)
            {
                inputLayer.AddNeuron(new InputNeuron(0, i));
            }

            hiddenLayers = new List<Layer>();
            var layerIndex = 1;
            foreach (var numNeurons in numHidden)
            {
                var layer = new Layer();
                for (int i = 0; i < numNeurons; ++i)
                {
                    layer.AddNeuron(new HiddenNeuron(layerIndex, i, GetActivation(layerIndex)));
                }
                ++layerIndex;
                hiddenLayers.Add(layer);
            }

            outputLayer = new Layer();
            for (int i = 0; i < numOutput; ++i)
            {
                outputLayer.AddNeuron(new OutputNeuron(numHiddenLayers + 1, i, GetActivation(numHiddenLayers + 1)));
            }

            bias = new InputNeuron(-1, -1);
            bias.Value = 1.0;

            if (numHiddenLayers > 0)
            {
                foreach (var o in outputLayer)
                {
                    List<Connection> cons = new List<Connection>();
                    foreach (var n in hiddenLayers.Last())
                    {
                        cons.Add(new Connection(n));
                    }
                    cons.Add(new Connection(bias));
                    ((WorkingNeuron)o).Connections = cons;
                }

                foreach (var h in hiddenLayers[0])
                {
                    List<Connection> cons = new List<Connection>();
                    foreach (var n in inputLayer)
                    {
                        cons.Add(new Connection(n));
                    }
                    cons.Add(new Connection(bias));
                    ((WorkingNeuron)h).Connections = cons;
                }

                for (int i = 1; i < numHiddenLayers; ++i)
                {
                    foreach (var h in hiddenLayers[i])
                    {
                        List<Connection> cons = new List<Connection>();
                        foreach (var n in hiddenLayers[i - 1])
                        {
                            cons.Add(new Connection(n));
                        }
                        cons.Add(new Connection(bias));
                        ((WorkingNeuron)h).Connections = cons;
                    }
                }
            }
            else
            {
                foreach (var o in outputLayer)
                {
                    List<Connection> cons = new List<Connection>();
                    foreach (var n in inputLayer)
                    {
                        cons.Add(new Connection(n));
                    }
                    cons.Add(new Connection(bias));
                    ((WorkingNeuron)o).Connections = cons;
                }
            }
        }

        private Activation GetActivation(int index)
        {
            switch (strategy)
            {
                case ActivationStrategy.Random:
                    {
                        var r = new Random();
                        return Activation.Options[r.Next(0, Activation.Options.Count)];
                    }
                case ActivationStrategy.FixedRandom:
                    {
                        if (activationIndex == -1)
                        {
                            var r = new Random();
                            activationIndex = r.Next(0, Activation.Options.Count);
                        }
                        return Activation.Options[activationIndex];
                    }
                case ActivationStrategy.RoundRobin:
                    return Activation.Options[index % Activation.Options.Count];
                case ActivationStrategy.Fixed:
                    return activation;
                default:
                    return new Identity();
            }
        }
    }
}

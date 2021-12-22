using System;

namespace SharpBrain.Neural
{
    public class Connection
    {
        private readonly Neuron inputNeuron;

        private double weight = 0.0;

        public double Weight
        {
            get { return weight; }
        }

        public double NeuronValue
        {
            get { return inputNeuron.Value; }
        }

        public Connection(Neuron inputNeuron)
        {
            this.inputNeuron = inputNeuron;
            var rand = new Random();
            weight = rand.NextDouble() - 0.5;
        }

        public double Activate()
        {
            return inputNeuron.Activate() * weight;
        }

        public void AdjustWeight(double delta)
        {
            weight += delta;
        }
    }
}

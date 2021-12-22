using System.Collections;
using System.Collections.Generic;

namespace SharpBrain.Neural
{
    public class Layer : IEnumerable<Neuron>
    {
        private readonly List<Neuron> neurons;

        public Neuron this[int index]
        {
            get { return neurons[index]; }
        }

        public int Count
        {
            get { return neurons.Count; }
        }

        public Layer()
        {
            neurons = new List<Neuron>();
        }

        public Layer(List<Neuron> neurons)
        {
            this.neurons = neurons;
        }

        public void AddNeuron(Neuron neuron)
        {
            neurons.Add(neuron);
        }

        public IEnumerator<Neuron> GetEnumerator()
        {
            return neurons.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return neurons.GetEnumerator();
        }
    }
}

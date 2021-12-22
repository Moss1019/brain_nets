using SharpBrain.Activations;
using System.Collections.Generic;

namespace SharpBrain.Neural
{
    public abstract class WorkingNeuron : Neuron
    {
        protected readonly Activation activation;

        public List<Connection> Connections
        {
            get; set;
        }

        protected WorkingNeuron(int layerIndex, int index, Activation activation)
            : base(layerIndex, index)
        {
            this.activation = activation;
        }

        public override double Activate()
        {
            double s = 0.0;
            foreach (var con in Connections)
            {
                s += con.Activate();
            }
            netInput = s;
            Value = activation.Activate(s);
            return Value;
        }

        public void ApplyDelta()
        {
            foreach (var con in Connections)
            {
                var deltaWeight = ETA * delta * con.NeuronValue;
                con.AdjustWeight(deltaWeight);
            }
        }
    }
}

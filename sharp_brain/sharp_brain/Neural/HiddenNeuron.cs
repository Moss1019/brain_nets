using SharpBrain.Activations;

namespace SharpBrain.Neural
{
    public class HiddenNeuron : WorkingNeuron
    {
        public HiddenNeuron(int layerIndex, int index, Activation activation)
            : base(layerIndex, index, activation)
        {

        }

        public void CalculateDelta(Layer nextLayer)
        {
            var derivative = activation.Derivative(netInput);
            var s = 0.0;
            foreach (var n in nextLayer)
            {
                var workingNeuron = n as WorkingNeuron;
                s += workingNeuron.Delta * workingNeuron.Connections[index].Weight;
            }
            delta = derivative * s;
        }
    }
}

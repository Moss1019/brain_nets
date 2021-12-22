using SharpBrain.Activations;

namespace SharpBrain.Neural
{
    public class OutputNeuron : WorkingNeuron
    {
        public OutputNeuron(int layerIndex, int index, Activation activation)
            : base(layerIndex, index, activation)
        {

        }

        public void CalculateDelta(double expected)
        {
            var derivative = activation.Derivative(netInput);
            var difference = expected - Value;
            delta = derivative * difference;
        }
    }
}

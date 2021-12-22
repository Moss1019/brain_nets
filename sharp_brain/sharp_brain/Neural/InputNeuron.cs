namespace SharpBrain.Neural
{
    public class InputNeuron : Neuron
    {
        public InputNeuron(int layerIndex, int index)
            : base(layerIndex, index)
        {

        }

        public override double Activate()
        {
            return Value;
        }
    }
}

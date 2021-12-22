namespace SharpBrain.Neural
{
    public abstract class Neuron
    {
        protected static readonly double ETA = 1.0;

        protected double netInput = 0.0;
        protected double delta = 0.0;
        protected int layerIndex = 0;
        protected int index = 0;

        public double Value { get; set; }

        public double NetInput
        {
            get { return netInput; }
        }

        public double Delta
        {
            get { return delta; }
        }

        protected Neuron(int layerIndex, int index)
        {
            this.layerIndex = layerIndex;
            this.index = index;
        }

        public abstract double Activate();
    }
}

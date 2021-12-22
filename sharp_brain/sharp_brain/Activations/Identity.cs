namespace SharpBrain.Activations
{
    class Identity : Activation
    {
        public override double Activate(double x)
        {
            return x;
        }

        public override double Derivative(double x)
        {
            return 1.0;
        }
    }
}

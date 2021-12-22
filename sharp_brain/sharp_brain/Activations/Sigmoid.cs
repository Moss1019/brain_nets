using System;

namespace SharpBrain.Activations
{
    public class Sigmoid : Activation
    {
        public override double Activate(double x)
        {
            return 1.0 / (1 + Math.Pow(Math.E, -x));
        }

        public override double Derivative(double x)
        {
            var sig = Activate(x);
            return sig * (1 - sig);
        }
    }
}

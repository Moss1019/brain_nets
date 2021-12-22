
using System.Collections.Generic;

namespace SharpBrain.Activations
{
    public abstract class Activation
    {
        public static readonly List<Activation> Options = new List<Activation>()
        {
            new Sigmoid(),
            new Identity()
        };

        public abstract double Activate(double x);

        public abstract double Derivative(double x);
    }
}

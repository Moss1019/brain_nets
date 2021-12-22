using SharpBrain.Activations;
using SharpBrain.Neural;
using System;
using System.Collections.Generic;

namespace SharpBrain
{
    static class Program
    {
        static void Main(string[] args)
        {
            var r1 = new Random();
            var r2 = new Random();
            var inputs = new List<List<double>>();
            var outputs = new List<List<double>>();
            for (int i = 0; i < 350; ++i)
            {
                double i1 = r1.NextDouble() > 0.5 ? 1.0 : 0.0;
                double i2 = r2.NextDouble() > 0.5 ? 1.0 : 0.0;
                double o = i1 == 1.0 && i2 == 1.0 ? 1.0 : 0.0;
                inputs.Add(new List<double>() { i1, i2 });
                outputs.Add(new List<double>() { o });
            }

            List<int> topology = new List<int>() { 2, 3, 2, 1 };

            var nn = new NeuralNet(topology, ActivationStrategy.RoundRobin);

            nn.Train(inputs, outputs, 500);

            var prediction = nn.Predict(new List<double>() { 1.0, 1.0 });
            foreach (var pred in prediction)
            {
                Console.WriteLine(pred);
            }
            prediction = nn.Predict(new List<double>() { 0.0, 1.0 });
            foreach (var pred in prediction)
            {
                Console.WriteLine(pred);
            }
        }
    }
}

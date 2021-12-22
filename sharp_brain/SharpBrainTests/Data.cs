using System;
using System.Collections.Generic;

namespace SharpBrainTests
{
    static class Data
    {
        public record Logical(List<List<double>> inputs, List<List<double>> outputs);

        public static Logical LogicalAnd(int numSamples)
        {
            var r1 = new Random();
            var r2 = new Random();
            var inputs = new List<List<double>>();
            var outputs = new List<List<double>>();
            for (int i = 0; i < numSamples; ++i)
            {
                double i1 = r1.NextDouble() > 0.5 ? 1.0 : 0.0;
                double i2 = r2.NextDouble() > 0.5 ? 1.0 : 0.0;
                double o = i1 == i2 && i1 == 1.0 ? 1.0 : 0.0;
                inputs.Add(new List<double>() { i1, i2 });
                outputs.Add(new List<double>() { o });
            }
            return new Logical(inputs, outputs);
        }

        public static Logical LogicalOr(int numSamples)
        {
            var r1 = new Random();
            var r2 = new Random();
            var inputs = new List<List<double>>();
            var outputs = new List<List<double>>();
            for (int i = 0; i < numSamples; ++i)
            {
                double i1 = r1.NextDouble() > 0.5 ? 1.0 : 0.0;
                double i2 = r2.NextDouble() > 0.5 ? 1.0 : 0.0;
                double o = (i1 == 1.0 || i2 == 1.0) ? 1.0 : 0.0;
                inputs.Add(new List<double>() { i1, i2 });
                outputs.Add(new List<double>() { o });
            }
            return new Logical(inputs, outputs);
        }
    }
}

using Microsoft.VisualStudio.TestTools.UnitTesting;
using SharpBrain.Activations;
using SharpBrain.Neural;
using System;
using System.Collections.Generic;

namespace SharpBrainTests
{
    [TestClass]
    public class NeuralNetTests
    {
        [TestMethod]
        public void LogicalAnd_1_1_1()
        {
            // arrange
            var sut = new NeuralNet(new List<int>() { 2, 2, 1 }, new Sigmoid());
            var data = Data.LogicalAnd(350);

            // act
            sut.Train(data.inputs, data.outputs);
            var testInput = new List<double>() { 1.0, 1.0 };
            var actual = sut.Predict(testInput);

            // assert 
            Assert.IsTrue(Math.Round(actual[0], 0) == 1.0, $"{actual[0]} not 1.0");
        }

        [TestMethod]
        public void LogicalAnd_1_0_0()
        {
            // arrange
            var sut = new NeuralNet(new List<int>() { 2, 2, 1 }, new Sigmoid());
            var data = Data.LogicalAnd(300);

            // act
            sut.Train(data.inputs, data.outputs);
            var testInput = new List<double>() { 1.0, 0.0 };
            var actual = sut.Predict(testInput);

            // assert 
            Assert.IsTrue(Math.Round(actual[0], 0) == 0.0, $"{actual[0]} not 0.0");
        }

        [TestMethod]
        public void LogicalAnd_0_0_0()
        {
            // arrange
            var sut = new NeuralNet(new List<int>() { 2, 2, 1 }, new Sigmoid());
            var data = Data.LogicalAnd(300);

            // act
            sut.Train(data.inputs, data.outputs);
            var testInput = new List<double>() { 0.0, 0.0 };
            var actual = sut.Predict(testInput);

            // assert 
            Assert.IsTrue(Math.Round(actual[0], 0) == 0.0, $"{actual[0]} not 0.0");
        }

        [TestMethod]
        public void LogicalAnd_0_1_0()
        {
            // arrange
            var sut = new NeuralNet(new List<int>() { 2, 2, 1 }, new Sigmoid());
            var data = Data.LogicalAnd(300);

            // act
            sut.Train(data.inputs, data.outputs);
            var testInput = new List<double>() { 0.0, 1.0 };
            var actual = sut.Predict(testInput);

            // assert 
            Assert.IsTrue(Math.Round(actual[0], 0) == 0.0, $"{actual[0]} not 0.0");
        }

        [TestMethod]
        public void LogicalOr_1_1_1()
        {
            // arrange
            var sut = new NeuralNet(new List<int>() { 2, 2, 1 }, new Sigmoid());
            var data = Data.LogicalOr(350);

            // act
            sut.Train(data.inputs, data.outputs);
            var testInput = new List<double>() { 1.0, 1.0 };
            var actual = sut.Predict(testInput);

            // assert 
            Assert.IsTrue(Math.Round(actual[0], 0) == 1.0, $"{actual[0]} not 1.0");
        }

        [TestMethod]
        public void LogicalOr_1_0_1()
        {
            // arrange
            var sut = new NeuralNet(new List<int>() { 2, 2, 1 }, new Sigmoid());
            var data = Data.LogicalOr(300);

            // act
            sut.Train(data.inputs, data.outputs);
            var testInput = new List<double>() { 1.0, 0.0 };
            var actual = sut.Predict(testInput);

            // assert 
            Assert.IsTrue(Math.Round(actual[0], 0) == 1.0, $"{actual[0]} not 1.0");
        }

        [TestMethod]
        public void LogicalOr_0_0_0()
        {
            // arrange
            var sut = new NeuralNet(new List<int>() { 2, 2, 1 }, new Sigmoid());
            var data = Data.LogicalOr(300);

            // act
            sut.Train(data.inputs, data.outputs);
            var testInput = new List<double>() { 0.0, 0.0 };
            var actual = sut.Predict(testInput);

            // assert 
            Assert.IsTrue(Math.Round(actual[0], 0) == 0.0, $"{actual[0]} not 0.0");
        }

        [TestMethod]
        public void LogicalOr_0_1_1()
        {
            // arrange
            var sut = new NeuralNet(new List<int>() { 2, 2, 1 }, new Sigmoid());
            var data = Data.LogicalOr(300);

            // act
            sut.Train(data.inputs, data.outputs);
            var testInput = new List<double>() { 0.0, 1.0 };
            var actual = sut.Predict(testInput);

            // assert 
            Assert.IsTrue(Math.Round(actual[0], 0) == 1.0, $"{actual[0]} not 1.0");
        }
    }
}

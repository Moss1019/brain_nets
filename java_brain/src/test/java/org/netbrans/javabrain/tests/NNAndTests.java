package org.netbrans.javabrain.tests;

import org.netbrains.javabrain.neural.NeuralNet;
import org.testng.Assert;
import org.testng.annotations.BeforeTest;
import org.testng.annotations.Test;

import java.util.ArrayList;
import java.util.List;

public class NNAndTests {
    private NeuralNet sut;
    private List<List<Double>> inputVectors;
    private List<List<Double>> expected;

    @BeforeTest
    public void init() {
        List<Integer> topology = new ArrayList<>();
        topology.add(2);
        topology.add(2);
        topology.add(1);
        sut = new NeuralNet(topology);
        inputVectors = new ArrayList<>();
        for(int i = 0; i < 500; ++i) {
            List<Double> ins = new ArrayList<>();
            ins.add(i % 3 == 0 ? 1.0 : 0.0);
            ins.add(i % 5 == 0 ? 1.0 : 0.0);
            inputVectors.add(ins);
        }
        expected = new ArrayList<>();
        for(List<Double> i : inputVectors) {
            List<Double> ex = new ArrayList<>();
            ex.add(i.get(0) == 1.0 && i.get(1) == 1.0 ? 1.0 : 0.0);
            expected.add(ex);
        }
    }

    @Test
    public void shouldBe_1_inputs_1_1() {
        // Arrange
        List<Double> inputs = new ArrayList<>();
        inputs.add(1.0);
        inputs.add(1.0);

        // Act
        sut.train(inputVectors, expected, 500);
        List<Double> actual = sut.predict(inputs);

        // Assert
        for(double o : actual) {
            System.out.println("1.0 and 1.0 " + o);
            Assert.assertEquals(Math.round(o), 1.0);
        }
    }

    @Test
    public void shouldBe_0_inputs_1_0() {
        // Arrange
        List<Double> inputs = new ArrayList<>();
        inputs.add(1.0);
        inputs.add(0.0);

        // Act
        sut.train(inputVectors, expected, 100);
        List<Double> actual = sut.predict(inputs);

        // Assert
        for(double o : actual) {
            System.out.println("1.0 and 0.0 " + o);
            Assert.assertEquals(Math.round(o), 0.0);
        }
    }

    @Test
    public void shouldBe_0_inputs_0_1() {
        // Arrange
        List<Double> inputs = new ArrayList<>();
        inputs.add(1.0);
        inputs.add(0.0);

        // Act
        sut.train(inputVectors, expected, 100);
        List<Double> actual = sut.predict(inputs);

        // Assert
        for(double o : actual) {
            System.out.println("1.0 and 0.0 " + o);
            Assert.assertEquals(Math.round(o), 0.0);
        }
    }

    @Test
    public void shouldBe_0_inputs_0_0() {
        // Arrange
        List<Double> inputs = new ArrayList<>();
        inputs.add(0.0);
        inputs.add(0.0);

        // Act
        sut.train(inputVectors, expected, 100);
        List<Double> actual = sut.predict(inputs);

        // Assert
        for(double o : actual) {
            System.out.println("0.0 and 0.0 " + o);
            Assert.assertEquals(Math.round(o), 0.0);
        }
    }
}

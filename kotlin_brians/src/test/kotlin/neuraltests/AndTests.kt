package neuraltests

import neurals.NeuralNet
import org.junit.Test
import kotlin.math.round

class AndTests {
    private val topology: Array<Int> = arrayOf(2, 2, 1)

    @Test
    fun given_1_1_shouldBe_1() {
        // Arrange
        val sut = NeuralNet(topology)
        val (ins, out) = getData()

        // Act
        sut.train(ins, out)
        val actual = sut.predict(arrayOf(1.0, 1.0))

        // Assert
        val expected: Double = 1.0
        println("expected $expected, got ${actual[0]}")
        assert(round(actual[0]) == expected)
    }

    @Test
    fun given_0_1_shouldBe_0() {
        // Arrange
        val sut = NeuralNet(topology)
        val (ins, out) = getData()

        // Act
        sut.train(ins, out)
        val actual = sut.predict(arrayOf(0.0, 1.0))

        // Assert
        val expected: Double = 0.0
        println("expected $expected, got ${actual[0]}")
        assert(round(actual[0]) == expected)
    }

    @Test
    fun given_1_0_shouldBe_0() {
        // Arrange
        val sut = NeuralNet(topology)
        val (ins, out) = getData()

        // Act
        sut.train(ins, out)
        val actual = sut.predict(arrayOf(1.0, 0.0))

        // Assert
        val expected: Double = 0.0
        println("expected $expected, got ${actual[0]}")
        assert(round(actual[0]) == expected)
    }

    @Test
    fun given_0_0_shouldBe_0() {
        // Arrange
        val sut = NeuralNet(topology)
        val (ins, out) = getData()

        // Act
        sut.train(ins, out)
        val actual = sut.predict(arrayOf(0.0, 0.0))

        // Assert
        val expected: Double = 0.0
        println("expected $expected, got ${actual[0]}")
        assert(round(actual[0]) == expected)
    }

    private fun getData(): Pair<List<Array<Double>>, List<Array<Double>>> {
        val pair: Pair<MutableList<Array<Double>>, MutableList<Array<Double>>> = Pair(mutableListOf(), mutableListOf())
        for(i in 0..500) {
            val ins = arrayOf(if(i % 3 == 0) 1.0 else 0.0, if(i % 5 == 0) 1.0 else 0.0)
            val out = arrayOf(if(i % 3 == 0 && i % 5 == 0) 1.0 else 0.0)
            pair.first.add(ins)
            pair.second.add(out)
        }
        return pair
    }
}
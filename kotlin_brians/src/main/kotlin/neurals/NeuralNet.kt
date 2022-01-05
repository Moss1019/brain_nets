package neurals

import activations.Sigmoid

class NeuralNet(topology: Array<Int>) {
    private var input: MutableList<InputNeuron> = mutableListOf()
    private var output: MutableList<OutputNeuron> = mutableListOf()
    private var hidden: MutableList<MutableList<HiddenNeuron>> = mutableListOf()

    private val numInput = topology[0]
    private val numOutput = topology[topology.size - 1]
    private val numHiddenLayers = topology.size - 2
    private val hiddenLayerCounts = topology.copyOfRange(1, topology.size - 1)

    init {
        for(i in 0 until numInput) {
            input.add(InputNeuron(0, i))
        }
        for(i in 0 until numHiddenLayers) {
            val layer: MutableList<HiddenNeuron> = mutableListOf()
            for(j in 0 until hiddenLayerCounts[i]) {
                layer.add(HiddenNeuron(i + 1, j, Sigmoid()))
            }
            hidden.add(layer)
        }
        for(i in 0 until numOutput) {
            output.add(OutputNeuron(numHiddenLayers + 1, i, Sigmoid()))
        }

        if(numHiddenLayers > 0) {
            for(o in output) {
                val connections: MutableList<Connection> = mutableListOf()
                for(h in hidden[numHiddenLayers - 1]) {
                    connections.add(Connection(h))
                }
                connections.add(Connection(BiasNeuron(numHiddenLayers, 1.0)))
                o.connections = connections
            }
            for(h in hidden[0]) {
                val connections: MutableList<Connection> = mutableListOf()
                for(i in input) {
                    connections.add(Connection(i))
                }
                connections.add(Connection(BiasNeuron(0, 1.0)))
                h.connections = connections
            }
            for(i in 1 until numHiddenLayers) {
                for(h1 in hidden[i]) {
                    val connections: MutableList<Connection> = mutableListOf()
                    for(h2 in hidden[i - 1]) {
                        connections.add(Connection(h2))
                    }
                    connections.add(Connection(BiasNeuron(i, 1.0)))
                    h1.connections = connections
                }
            }
        } else {
            for(o in output) {
                val connections: MutableList<Connection> = mutableListOf()
                for(i in input) {
                    connections.add(Connection(i))
                }
                connections.add(Connection(BiasNeuron(0, 1.0)))
                o.connections = connections
            }
        }
    }

    fun predict(input: Array<Double>): List<Double> {
        for(i in 0 until numInput) {
            this.input[i].value = input[i]
        }
        val output: MutableList<Double> = mutableListOf()
        for(o in this.output) {
            output.add(o.activate())
        }
        return output
    }

    fun train(inputs: List<Array<Double>>, expected: List<Array<Double>>, iterations: Int = 500) {
        for(i in 0..iterations) {
            for(j in inputs.indices) {
                val ins = inputs[j]
                val exd = expected[j]
                predict(ins)

                for(k in output.indices) {
                    output[k].calculateDelta(exd[k])
                }
                for(k in numHiddenLayers - 1 downTo 0) {
                    for(h in hidden[k]) {
                        h.calculateDelta(if (k == numHiddenLayers - 1) output else hidden[k + 1] )
                    }
                }

                for(o in output) {
                    o.applyDelta()
                }
                for(l in hidden) {
                    for(h in l) {
                        h.applyDelta()
                    }
                }
            }
        }
    }
}
import neurals.NeuralNet

fun main(args: Array<String>) {
    val nn = NeuralNet(arrayOf(2, 3, 1))

    val p1 = nn.predict(arrayOf(1.0, 1.0))
    for(o in p1) {
        println(o)
    }

    val p3 = nn.predict(arrayOf(1.0, 1.0))
    for(o in p3) {
        println(o)
    }

    nn.train(listOf(arrayOf(1.0, 1.0)), listOf(arrayOf(1.0)))

    val p2 = nn.predict(arrayOf(1.0, 1.0))
    for(o in p2) {
        println(o)
    }
}

class XorTests {
    public func test() {
        let topology = [2, 2, 1]
        let nn = NeuralNet(topology: topology)
        let data = generateData()
        nn.train(input: data.0, expected: data.1, iterations: 500)
        print("Expecting 0.0 got \(nn.predict(input: [1.0, 1.0]))")
        print("Expecting 1.0 got \(nn.predict(input: [0.0, 1.0]))")
        print("Expecting 1.0 got \(nn.predict(input: [1.0, 0.0]))")
        print("Expecting 0.0 got \(nn.predict(input: [0.0, 0.0]))")
    }
    
    private func generateData() -> ([[Double]], [[Double]]) {
        var input: [[Double]] = []
        var output: [[Double]] = []
        for i in 0...500 {
            input.append([i % 3 == 0 ? 1.0 : 0.0, i % 5 == 0 ? 1.0 : 0.0])
            output.append([(i % 3 == 0 && i % 5 != 0) || (i % 3 != 0 && i % 5 == 0) ? 1.0 : 0.0])
        }
        return (input, output)
    }
}

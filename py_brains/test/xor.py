
from src.neural_net import NeuralNet


def get_training_data():
    inputs = []
    expected = []
    for i in range(200):
        inputs.append([1.0 if i % 3 == 0 else 0.0, 1.0 if i % 5 == 0 else 0.0])
        expected.append([1.0 if (i % 3 == 0 and i % 5 != 0) or (i % 3 != 0 and i % 5 == 0) else 0.0])
    return inputs, expected


def main():
    training_data = get_training_data()

    nn = NeuralNet([2, 2, 1], True)
    nn.add_connection(0, 0, 2, 0)
    nn.add_connection(0, 1, 2, 0)

    nn.train(training_data[0], training_data[1], 10000)

    [print(round(v)) for v in nn.predict([1.0, 1.0])]
    [print(round(v)) for v in nn.predict([0.0, 0.0])]
    [print(round(v)) for v in nn.predict([0.0, 1.0])]
    [print(round(v)) for v in nn.predict([1.0, 0.0])]


if __name__ == '__main__':
    main()

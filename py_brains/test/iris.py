
from src.neural_net import NeuralNet

keys = {
    'Iris-virginica': [1.0, 0.0, 0.0],
    'Iris-versicolor': [0.0, 1.0, 0.0],
    'Iris-setosa': [0.0, 0.0, 1.0]
}


def get_training_data():
    training_inputs = []
    training_expected = []
    test_inputs = []
    test_expected = []

    f = open('iris.data')
    lines = f.readlines()
    f.close()

    index = 0
    min_val = 1000.0
    max_val = 0.0
    input_data = []
    output_data = []

    for line in lines:
        parts = line.split(',')
        sepal_length = float(parts[0])
        sepal_width = float(parts[1])
        petal_length = float(parts[2])
        petal_width = float(parts[3])
        cls = parts[4].strip()

        min_val = min(min_val, sepal_length)
        min_val = min(min_val, sepal_width)
        min_val = min(min_val, petal_length)
        min_val = min(min_val, petal_width)

        max_val = max(max_val, sepal_length)
        max_val = max(max_val, sepal_width)
        max_val = max(max_val, petal_length)
        max_val = max(max_val, petal_width)

        input_data.append([sepal_length,
                           sepal_width,
                           petal_length,
                           petal_width])
        output_data.append(keys[cls])

    for datum in input_data:
        for i in range(len(datum)):
            datum[i] = (datum[i] - min_val) / (max_val - min_val)

    for inputs, output in zip(input_data, output_data):
        if index % 51 == 0:
            test_inputs.append(inputs)
            test_expected.append(output)
        else:
            training_inputs.append(inputs)
            training_expected.append(output)
        index += 1
    return training_inputs, training_expected, test_inputs, test_expected


def main():
    training_data = get_training_data()

    nn = NeuralNet([4, 4, 3])

    nn.train(training_data[0], training_data[1], 5000)

    for i, o in zip(training_data[2], training_data[3]):
        print(i)
        print(nn.predict(i), end='::')
        print(o)
        print()


if __name__ == '__main__':
    main()

# net_brains
This repo contains neural network implementations in different programming languages

## About
I am currently learning about neural networks and machine learning in general. This repository will be where everything I learn and make will be documented.

## Implementations
- Swift
- Python
- C#
- Java
- Kotlin
- C++
- C

# How a feed forward back propagating network works
## Structure
A neural network has a number of layers with 1 or more neurons per layer. The first layer is the input layer. When implementing this layer, it is important to allow the values of the neurons to be set. The last layer is the output layer, this layer gives the result of the whole network doing its work. The layers between the input and the output layer are known as the hidden layers.

In addition to neurons, the network also has connections between different neurons. These connections link different layers together, or different neurons in the same layer. Every connection has a weight associated with it. I.e. the weight that the input neuron has on the output neuron. Mathematically this is denoted with W<sub>ij</sub>, where i is the output neuron, and j is the input neuron.

<pre>
0----0----0
 \  /    /
  \/    /
  /\   /
 /  \ /
0----0
</pre>
A neural network with two inputs, one hidden layer with two neurons and one output

## Feed forward
### Weighted sum and activation function
The weighted sum is also known as the net input for a particular neuron. Let's say that we have neuron X, and it is connected to 2 neurons in the previous layer. These connections have the weights 0.3 and 0.5. The 2 neurons have the inputs 1.0 and 0.0. To calculate the net input for neuron X, we take the input values from the neurons, multiplied with their respective conneciton weights, and sum all these values together. In out example that would be 1.0 * 0.3 + 0.0 * 0.5 = 0.3. 

The actual output of neuron X would be the result of running the net input through and activation function.

## Activation functions
Using an activation function gives the network its non-linear qualities. Something like the sigmoid, or hyperbolic tangent.
- Identity
- Sigmoid
- Hyperbolic tangent

## Back propagation
The purpose of backpropagation is to incrementally update the weights of all the connections, starting from the back, moving to the first hidden layer.
### Calculating deltas
The delta refers to an amount that has a close relation with the neuron's contribution to the network error. An output neuron is simple to calculate, take the expected value and subtract the actual value. For hidden neurons, the process is more complicated. For each connection between the hidden neuron and the neurons in the <strong>next</strong> layer, calculate the weighted sum of the next layer's neuron's delta, and the weight to that neuron. This works because the next layer's deltas should already be calculated. 

Let's say we calculated the deltas of the output layer, and we're about to calculate the deltas for the last hidden layer, we need the deltas of he output neurons in the calculation. If we calculate the deltas for the second to last hidden layer, we need the deltas of the last hidden layer, and so forth. Input neurons don't need to have deltas, because the only exist to provide the input of the network.

When using activation functions, you should also take the result of the net input ran through the derivative of the activation function.

For output neurons the calculation for the delta is: f'(net input) * (expected value - actual value) <br />
For hidden layer neurons the calculation is: f'(net input) * (sum of all the deltas of the next layer multiplied with the weight to those neurons)

### Updating weights
After the deltas have been calculated, the weights of the connections can be updated. This is done be adjusting the weight by an amount, not completely replacing the value.
The connection being updated is the connection between a neuron and its connections in the <strong>previous</strong> layer.
deltaW<sub>ij</sub> = eta * delta<sub>i</sub> * activation<sub>j</sub>

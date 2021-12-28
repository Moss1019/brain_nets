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

0----0----0
 \  /    /
  \/    /
  /\   /
 /  \ /
0----0

## Feed forward
### Weighted sum

## Back propagation
### Calculating deltas

### Updating weights


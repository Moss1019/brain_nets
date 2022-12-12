cmake_minimum_required(VERSION 3.20)
project(net_brains)

add_executable(net_brains main.cpp
    neuron.cpp
    sigmoid.cpp
    identity.cpp
    neuralnet.cpp
    activation.cpp
    biasneuron.cpp
    connection.cpp
    inputneuron.cpp
    hiddenneuron.cpp
    outputneuron.cpp
    workingneuron.cpp
)

target_link_libraries(net_brains PRIVATE pthread sfml-graphics sfml-window sfml-system)
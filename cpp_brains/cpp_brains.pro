TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        activation.cpp \
        biasneuron.cpp \
        connection.cpp \
        hiddenneuron.cpp \
        identity.cpp \
        inputneuron.cpp \
        main.cpp \
        neuralnet.cpp \
        neuron.cpp \
        outputneuron.cpp \
        sigmoid.cpp \
        workingneuron.cpp

HEADERS += \
    activation.h \
    biasneuron.h \
    connection.h \
    globals.h \
    hiddenneuron.h \
    identity.h \
    inputneuron.h \
    neuralnet.h \
    neuron.h \
    outputneuron.h \
    sigmoid.h \
    workingneuron.h

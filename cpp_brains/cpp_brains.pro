TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        connection.cpp \
        identity.cpp \
        inputneuron.cpp \
        main.cpp \
        neuron.cpp \
        sigmoid.cpp \
        workingneuron.cpp

HEADERS += \
    activation.h \
    connection.h \
    globals.h \
    identity.h \
    inputneuron.h \
    neuron.h \
    sigmoid.h \
    workingneuron.h

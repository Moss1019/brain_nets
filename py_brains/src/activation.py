

class Activation(object):
    def __init__(self, f, f_d):
        self._f = f
        self._f_d = f_d

    def activate(self, x):
        return self._f(x)

    def derivative(self, x):
        return self._f_d(x)

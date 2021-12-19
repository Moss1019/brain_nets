
from random import random

import math


def sig(net_input):
    return 1.0 / (1 + pow(math.e, -net_input))

print(sig(1.436))

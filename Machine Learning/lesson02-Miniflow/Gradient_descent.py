from sympy import *
import numpy as np
import random



def gradient_descent_update(x, gradx, learning_rate):
    """
    Performs a gradient descent update.
    """
    x = x - learning_rate * gradx
    
    # Return the new value for x
    return x


def f(x):
    """
    Quadratic function.
    It's easy to see the minimum value of the function
    is 5 when is x=0.
    """
    return x**2 + 5

def df(x):
    """
    Derivative of `f` with respect to `x`.
    """
    return 2*x
    #return f(x).diff(x)

# Random number between 0 and 10,000. Feel free to set x whatever you like.
x = random.randint(0, 10000)
learning_rate = 0.1
epochs = 100

for i in range(epochs+1):
    cost = f(x)
    gradx = df(x)
    print("EPOCH {}: Cost = {:.3f}, x = {:.3f}".format(i, cost, gradx))
    x = gradient_descent_update(x, gradx, learning_rate)

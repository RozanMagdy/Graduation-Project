import numpy as np
import math 

class Node(object):
    def __init__(self, inbound_nodes=[]):
        # Node(s) from which this Node receives values
        self.inbound_nodes = inbound_nodes
        # Node(s) to which this Node passes values
        self.outbound_nodes = []
        # their values are the partials of this node with
        # respect to that input.
        self.gradients = {}
        # A calculated value
        self.value = None
        # For each inbound_node, add the current Node as an outbound_node.
        for n in self.inbound_nodes:
            n.outbound_nodes.append(self)
        

    def forward(self):
        pass

    def backward(self):
        pass
    

class Input(Node):
    def __init__(self):
        # An Input node has no inbound nodes,
        # so no need to pass anything to the Node instantiator.
        Node.__init__(self)
        
    def backward(self):
        # An Input node has no inputs so the gradient (derivative)
        # is zero.
        # The key, `self`, is reference to this object.
        self.gradients = {self: 0}
        # Weights and bias may be inputs, so you need to sum
        # the gradient from output gradients.
        for n in self.outbound_nodes:
            grad_cost = n.gradients[self]
            self.gradients[self] += grad_cost * 1

class Add2(Node):
    def __init__(self,x,y):  
        Node.__init__(self,[x,y])

    def forward(self):
        x_value = self.inbound_nodes[0].value
        y_value = self.inbound_nodes[1].value
        self.value = x_value + y_value

        
        
class Add(Node):
    def __init__(self, INPUTS):  #INPUTS is a list of n input nodes
        Node.__init__(self, INPUTS)

    def forward(self):
        self.value = 0
        for i in INPUTS:
            value = self.inbound_nodes[i].value
            self.value = self.value+value


class Linear(Node):
    def __init__(self, inputs, weights, bias):
        Node.__init__(self, [inputs, weights, bias])

    def forward(self):
        inputs = self.inbound_nodes[0].value
        weights = self.inbound_nodes[1].value
        bias = self.inbound_nodes[2].value
        self.value = bias
        for x in inputs:
            for w in weights:
                self.value += x * w
##        for x, w in zip(inputs, weights):
##            self.value += x * w

class LinearVector(Node):
    def __init__(self, X, W, B):
        Node.__init__(self, [X, W, B])
        
    def forward(self):
        X = self.inbound_nodes[0].value
        W = self.inbound_nodes[1].value
        B = self.inbound_nodes[2].value
        self.value = np.dot(X, W) + B

    def backward(self):
        """
        Calculates the gradient based on the output values.
        """
        # Initialize a partial for each of the inbound_nodes.
        self.gradients = {n: np.zeros_like(n.value) for n in self.inbound_nodes}
        # Cycle through the outputs. The gradient will change depending
        # on each output, so the gradients are summed over all outputs.
        for n in self.outbound_nodes:
            # Get the partial of the cost with respect to this node.
            grad_cost = n.gradients[self]
            # Set the partial of the loss with respect to this node's inputs.
            self.gradients[self.inbound_nodes[0]] += np.dot(grad_cost, self.inbound_nodes[1].value.T)
            # Set the partial of the loss with respect to this node's weights.
            self.gradients[self.inbound_nodes[1]] += np.dot(self.inbound_nodes[0].value.T, grad_cost)
            # Set the partial of the loss with respect to this node's bias.
            self.gradients[self.inbound_nodes[2]] += np.sum(grad_cost, axis=0, keepdims=False)


class Sigmoid(Node):
    def __init__(self, inputs):
        Node.__init__(self, [inputs])

    def _sigmoid(self, x):
        return 1. / (1. + np.exp(-x))

    def forward(self):
        input_value = self.inbound_nodes[0].value
        self.value = self._sigmoid(input_value)
        
    def backward(self):
        """
        Calculates the gradient using the derivative ofnthe sigmoid function.
        """
        # Initialize the gradients to 0.
        self.gradients = {n: np.zeros_like(n.value) for n in self.inbound_nodes}

        # Cycle through the outputs. The gradient will change depending
        # on each output, so the gradients are summed over all outputs.
        for n in self.outbound_nodes:
            # Get the partial of the cost with respect to this node.
            grad_cost = n.gradients[self]
            sigmoid = self.value
            self.gradients[self.inbound_nodes[0]] += sigmoid * (1 - sigmoid) * grad_cost

class MSE(Node):
    def __init__(self, y, a):
        Node.__init__(self, [y, a])

    def forward(self):
        y = self.inbound_nodes[0].value.reshape(-1, 1)
        a = self.inbound_nodes[1].value.reshape(-1, 1)
        self.value = np.mean(np.square(y-a))
    def backward(self):
        """
        Calculates the gradient of the cost.

        This is the final node of the network so outbound nodes
        are not a concern.
        """
        self.gradients[self.inbound_nodes[0]] = (2 / self.m) * self.diff
        self.gradients[self.inbound_nodes[1]] = (-2 / self.m) * self.diff

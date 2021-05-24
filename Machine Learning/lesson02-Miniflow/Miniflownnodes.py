import numpy as np
import math 

class Node(object):
    def __init__(self, inbound_nodes=[]):
        # Node(s) from which this Node receives values
        self.inbound_nodes = inbound_nodes
        # Node(s) to which this Node passes values
        self.outbound_nodes = []
        # For each inbound_node, add the current Node as an outbound_node.
        for n in self.inbound_nodes:
            n.outbound_nodes.append(self)
        # A calculated value
        self.value = None

    def forward(self):
        pass

class Input(Node):
    def __init__(self):
        # An Input node has no inbound nodes,
        # so no need to pass anything to the Node instantiator.
        Node.__init__(self)

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



class Sigmoid(Node):
    def __init__(self, inputs):
        Node.__init__(self, [inputs])

    def _sigmoid(self, x):
        return 1. / (1. + np.exp(-x))

    def forward(self):
        input_value = self.inbound_nodes[0].value
        self.value = self._sigmoid(input_value)


class MSE(Node):
    def __init__(self, y, a):
        Node.__init__(self, [y, a])

    def forward(self):
        y = self.inbound_nodes[0].value.reshape(-1, 1)
        a = self.inbound_nodes[1].value.reshape(-1, 1)
        self.value = np.mean(np.square(y-a))

    

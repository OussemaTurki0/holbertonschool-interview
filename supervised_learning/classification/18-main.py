#!/usr/bin/env python3
"""
Test for DeepNeuralNetwork class.
"""
import numpy as np
from deep_neural_network import DeepNeuralNetwork


def test_deep_neural_network():
    # Create a simple dataset for testing (2 features, 4 examples)
    X = np.array([[0, 0, 1, 1], [0, 1, 0, 1]])  # 2 features, 4 examples
    Y = np.array([[0, 1, 1, 0]])  # Labels (binary)

    # Initialize the deep neural network with 2 input features and 3 hidden layers
    nn = DeepNeuralNetwork(nx=2, layers=[3, 2, 1])  # 3 hidden layers

    # Forward propagation: perform the forward pass
    AL, cache = nn.forward_prop(X)

    # Check the shapes of the output and intermediary cache variables
    print("Forward propagation results:")
    print(f"Output (AL) shape: {AL.shape}")  # Should be (1, number of examples)
    
    # Print the cache keys and the shapes of intermediary values
    for key in cache:
        print(f"{key} shape: {cache[key].shape}")

    # Output final layer (should match shape of the number of examples)
    print(f"Output of the final layer A{nn.L}:\n{AL}")

    # Example cost calculation (can be added later)
    # cost = nn.cost(Y, AL)
    # print(f"Cost: {cost}")


if __name__ == "__main__":
    test_deep_neural_network()

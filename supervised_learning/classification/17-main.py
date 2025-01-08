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

    # Check the initialized weights and biases
    print("Initial weights and biases:")
    for layer in range(1, nn.L + 1):
        print(f"W{layer} shape: {nn.weights[f'W{layer}'].shape}")
        print(f"b{layer} shape: {nn.weights[f'b{layer}'].shape}")

    # Forward propagation: Let's add a method to forward propagate
    def forward_propagation(X):
        A = X
        for layer in range(1, nn.L + 1):
            Z = np.dot(nn.weights[f'W{layer}'], A) + nn.weights[f'b{layer}']
            A = 1 / (1 + np.exp(-Z))  # Sigmoid activation function
            nn.cache[f'A{layer}'] = A  # Store the output of each layer in cache
        return A

    # Perform forward propagation and print the final output (A3 for 3 layers)
    A = forward_propagation(X)
    print(f"Output of the deep neural network after forward propagation:\n{A}")

    # Example output for cost calculation (use your cost function here)
    # cost = nn.cost(Y, A)
    # print(f"Cost: {cost}")


if __name__ == "__main__":
    test_deep_neural_network()

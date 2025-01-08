#!/usr/bin/env python3
"""
Test for NeuralNetwork class.
"""
import numpy as np
from neural_network import NeuralNetwork


def test_neural_network():
    # Create a simple dataset for testing
    X = np.array([[0, 0, 1, 1], [0, 1, 0, 1]])  # 2 features, 4 examples
    Y = np.array([[0, 1, 1, 0]])  # Labels (binary)

    # Initialize the neural network with 2 input features and 2 hidden nodes
    nn = NeuralNetwork(nx=2, nodes=2)

    # Train the neural network
    predictions, cost = nn.train(X, Y, iterations=1000, alpha=0.1, verbose=True, graph=True, step=100)

    # Output the results
    print(f"Predictions:\n{predictions}")
    print(f"Cost: {cost}")


if __name__ == "__main__":
    test_neural_network()

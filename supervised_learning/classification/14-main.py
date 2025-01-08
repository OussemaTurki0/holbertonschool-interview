#!/usr/bin/env python3
import numpy as np
import unittest
NN = __import__('14-neural_network').NeuralNetwork

class TestNeuralNetwork(unittest.TestCase):
    def setUp(self):
        """Sets up the environment for each test"""
        self.nx = 5
        self.nodes = 3
        self.nn = NeuralNetwork(self.nx, self.nodes)

    def test_initialization(self):
        """Tests if the neural network is initialized correctly"""
        self.assertEqual(self.nn.W1.shape, (self.nodes, self.nx))
        self.assertEqual(self.nn.b1.shape, (self.nodes, 1))
        self.assertEqual(self.nn.W2.shape, (1, self.nodes))
        self.assertEqual(self.nn.b2.shape, (1, 1))
        self.assertEqual(self.nn.A1.shape, (self.nodes, 1))
        self.assertEqual(self.nn.A2.shape, (1, 1))

    def test_forward_prop(self):
        """Test the forward propagation method"""
        X = np.random.randn(self.nx, 4)  # 4 examples, 5 features
        Y = np.random.randint(0, 2, (1, 4))  # Binary labels for 4 examples
        A1, A2 = self.nn.forward_prop(X)
        self.assertEqual(A1.shape, (self.nodes, 4))
        self.assertEqual(A2.shape, (1, 4))

    def test_cost(self):
        """Tests the cost function"""
        X = np.random.randn(self.nx, 4)
        Y = np.random.randint(0, 2, (1, 4))
        _, A2 = self.nn.forward_prop(X)
        cost = self.nn.cost(Y, A2)
        self.assertIsInstance(cost, np.float64)

    def test_evaluate(self):
        """Test the evaluate method"""
        X = np.random.randn(self.nx, 4)
        Y = np.random.randint(0, 2, (1, 4))
        predictions, cost = self.nn.evaluate(X, Y)
        self.assertEqual(predictions.shape, (1, 4))
        self.assertIsInstance(cost, np.float64)

    def test_gradient_descent(self):
        """Test the gradient descent method"""
        X = np.random.randn(self.nx, 4)
        Y = np.random.randint(0, 2, (1, 4))
        A1, A2 = self.nn.forward_prop(X)
        initial_W1 = np.copy(self.nn.W1)
        initial_b1 = np.copy(self.nn.b1)
        self.nn.gradient_descent(X, Y, A1, A2, alpha=0.05)
        self.assertFalse(np.array_equal(initial_W1, self.nn.W1))
        self.assertFalse(np.array_equal(initial_b1, self.nn.b1))

    def test_train(self):
        """Test the training method"""
        X = np.random.randn(self.nx, 4)
        Y = np.random.randint(0, 2, (1, 4))
        predictions, cost = self.nn.train(X, Y, iterations=500, alpha=0.05)
        self.assertEqual(predictions.shape, (1, 4))
        self.assertIsInstance(cost, np.float64)


if __name__ == '__main__':
    unittest.main()

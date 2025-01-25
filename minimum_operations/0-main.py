#!/usr/bin/python3
import unittest
minOperations = __import__('0-minoperations').minOperations


class TestMinOperations(unittest.TestCase):
    
    def test_minOperations(self):
        # Test case 1: n is less than or equal to 1
        self.assertEqual(minOperations(1), 0)
        
        # Test case 2: n is a prime number
        self.assertEqual(minOperations(5), 5)
        
        # Test case 3: n is a composite number
        self.assertEqual(minOperations(12), 7)  # 2 + 2 + 3
        
        # Test case 4: n is a power of a prime
        self.assertEqual(minOperations(8), 8)  # 2 + 2 + 2
        
        # Test case 5: n is a large number
        self.assertEqual(minOperations(60), 16)  # 2 + 2 + 3 + 3
        
        # Test case 6: n is prime
        self.assertEqual(minOperations(37), 37)
        
        # Test case 7: n is 100 (2 * 2 * 5 * 5)
        self.assertEqual(minOperations(100), 14)  # 2 + 2 + 5 + 5
        
        # Test case 8: n is 1 (edge case)
        self.assertEqual(minOperations(1), 0)

if __name__ == '__main__':
    unittest.main()

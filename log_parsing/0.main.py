#!/usr/bin/env python3
"""
Test suite for the log parsing script
"""

import unittest
import subprocess


class TestLogParser(unittest.TestCase):
    def run_parser(self, input_data):
        """
        Helper function to run the parser script with input data
        """
        result = subprocess.run(
            ["python3", "log_parser.py"],  # Replace with your script filename
            input=input_data,
            text=True,
            capture_output=True
        )
        return result.stdout, result.stderr

    def test_basic_log(self):
        """
        Test with basic log lines
        """
        input_data = (
            "127.0.0.1 - [2024-07-02] \"GET /index.html\" 200 1234\n"
            "127.0.0.1 - [2024-07-02] \"POST /submit\" 404 567\n"
            "127.0.0.1 - [2024-07-02] \"GET /home\" 200 789\n"
            "127.0.0.1 - [2024-07-02] \"PUT /update\" 403 100\n"
            "127.0.0.1 - [2024-07-02] \"DELETE /remove\" 500 200\n"
        )
        output, error = self.run_parser(input_data)
        self.assertIn("File size:", output)
        self.assertIn("200: 2", output)
        self.assertIn("404: 1", output)
        self.assertIn("403: 1", output)
        self.assertIn("500: 1", output)
        self.assertEqual(error, "")

    def test_no_logs(self):
        """
        Test with no input data
        """
        input_data = ""
        output, error = self.run_parser(input_data)
        self.assertIn("File size: 0", output)
        self.assertEqual(error, "")

    def test_partial_logs(self):
        """
        Test with fewer than 10 lines
        """
        input_data = (
            "127.0.0.1 - [2024-07-02] \"GET /index.html\" 200 100\n"
            "127.0.0.1 - [2024-07-02] \"POST /login\" 401 300\n"
            "127.0.0.1 - [2024-07-02] \"GET /home\" 200 500\n"
        )
        output, error = self.run_parser(input_data)
        self.assertIn("File size: 900", output)
        self.assertIn("200: 2", output)
        self.assertIn("401: 1", output)
        self.assertEqual(error, "")

    def test_incorrect_logs(self):
        """
        Test with incorrect log format
        """
        input_data = (
            "127.0.0.1 - [2024-07-02] \"GET /index.html\" OKAY 100\n"
            "INVALID LOG LINE\n"
            "127.0.0.1 - [2024-07-02] \"POST /submit\" 200\n"
        )
        output, error = self.run_parser(input_data)
        self.assertIn("File size:", output)
        self.assertEqual(error, "")


if __name__ == "__main__":
    unittest.main()

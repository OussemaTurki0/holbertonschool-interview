#!/usr/bin/python3
"""
Log parsing script that reads log entries from stdin, computes the total file size,
and tracks the occurrence of certain HTTP status codes. 
After every 10 lines, or a keyboard interrupt, it prints the current statistics.
"""
import sys

def parse_log():
    total_size = 0
    status_codes = {
        200: 0,
        301: 0,
        400: 0,
        401: 0,
        403: 0,
        404: 0,
        405: 0,
        500: 0
    }

    count = 0
    try:
        for line in sys.stdin:
            count += 1
            line = line.strip()

            # Print line for debugging purposes
            print(f"Processing line: {line}")

            # Skip lines that don't match the expected format
            try:
                parts = line.split(' ')
                ip = parts[0]
                date = parts[1][1:-1]
                method = parts[3][1:]
                status_code = int(parts[5])
                file_size = int(parts[6])

                if status_code in status_codes:
                    status_codes[status_code] += 1
                total_size += file_size

            except (IndexError, ValueError):
                print(f"Skipping invalid line: {line}")
                continue

            if count % 10 == 0:
                print_stats(total_size, status_codes)

    except KeyboardInterrupt:
        print_stats(total_size, status_codes)
        raise

def print_stats(total_size, status_codes):
    print(f"File size: {total_size}")
    for code in sorted(status_codes):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")

if __name__ == "__main__":
    parse_log()

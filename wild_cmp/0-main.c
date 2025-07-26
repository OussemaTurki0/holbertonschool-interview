#include <stdio.h>
#include "holberton.h"

int main(void)
{
    int result;

    result = wildcmp("hello", "hello");
    printf("Test 1: %d\n", result);  // Should print 1

    result = wildcmp("hello", "he*o");
    printf("Test 2: %d\n", result);  // Should print 1

    result = wildcmp("hello", "h*llo");
    printf("Test 3: %d\n", result);  // Should print 1

    result = wildcmp("hello", "*o");
    printf("Test 4: %d\n", result);  // Should print 1

    result = wildcmp("hello", "h*world");
    printf("Test 5: %d\n", result);  // Should print 0

    result = wildcmp("abc", "a*c");
    printf("Test 6: %d\n", result);  // Should print 1

    result = wildcmp("abc", "*");
    printf("Test 7: %d\n", result);  // Should print 1

    result = wildcmp("", "*");
    printf("Test 8: %d\n", result);  // Should print 1

    result = wildcmp("abc", "");
    printf("Test 9: %d\n", result);  // Should print 0

    result = wildcmp("", "");
    printf("Test 10: %d\n", result);  // Should print 1

    return (0);
}

#include "regex.h"

/**
 * regex_match - checks if a pattern matches a given string
 * @str: the input string
 * @pattern: the regular expression pattern (supports '.' and '*')
 *
 * Return: 1 if match, 0 otherwise
 */
int regex_match(const char *str, const char *pattern)
{
    if (!pattern || !str)
        return (0);

    /* If pattern is empty, string must also be empty */
    if (*pattern == '\0')
        return (*str == '\0');

    /* Handle next char being '*' (zero or more of preceding char) */
    if (*(pattern + 1) == '*')
    {
        /* Match 0 occurrence of preceding char */
        if (regex_match(str, pattern + 2))
            return (1);

        /* Match 1 or more of the preceding char */
        if ((*str != '\0') && (*str == *pattern || *pattern == '.'))
            return (regex_match(str + 1, pattern));
        return (0);
    }

    /* Match current char and move forward */
    if ((*str != '\0') && (*str == *pattern || *pattern == '.'))
        return (regex_match(str + 1, pattern + 1));

    return (0);
}

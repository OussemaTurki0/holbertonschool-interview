#include "holberton.h"

/**
 * wildcmp - Compares two strings considering wildcards.
 * @s1: First string.
 * @s2: Second string, may contain wildcard '*'.
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*')
	{
		/* skip consecutive * characters in s2 */
		while (*s2 == '*')
			s2++;

		if (*s2 == '\0')
			return (1); /* '*' matches the rest */

		while (*s1 != '\0')
		{
			if (wildcmp(s1, s2))
				return (1);
			s1++;
		}
		return (0);
	}

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}

#include "main.h"
#include <stddef.h>

/**
 * _strchr -  locates a character in a string
 * @s: string
 * @c: char
 *
 * Return: a pointer to the first occurrence of the character c
 * in the string s
 */


char *_strchr(char *s, char c)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		if (*(s + i) != c)
			i++;
		else
			return (s + i);
	}
	if (c == '\0')
		return (s + i);
	return (NULL);
}

/**
 * _strcmp- compares two string
 * @s1: first string
 * @s2: second string
 * Return: 0 if its same
 * number negative if s1<s2
 * number positive if s1>s2
 */

int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/**
 * _strlen - return the length of a string
 * @s: char to check
 * Description: this will return the length of a string
 * Return: 0
 */

int _strlen(char *s)
{
	int a = 0;

	while (*s++)
		a++;
	return (a);
}

/**
 * _atoi - converts a string into an int
 * @s: string to convert
 *
 * Return: converted int
 **/

int _atoi(char *s)
{
	int neg = 1, x = 0;
	unsigned int result = 0;

	while (s[x] <= '9' && s[x] >= '0' && s[x] != '\0')
	{
		result = (result * 10) + (s[x] - '0');
		x++;
	}
	while (!(s[x] <= '9' && s[x] >= '0') && s[x] != '\0')
	{
		if (s[x] == '-')
			neg *= -1;
		x++;
	}
	result *= neg;
	return (result);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: string
 * Return: pointer
 */

char *_strdup(char *str)
{
	int i = 0, len = 0, n;
	char *strcp;

	if (str == NULL)
		return (NULL);
	while (*(str + len))
		len++;

	n = sizeof(char) * (len + 1);

	strcp = malloc(n);

	if (strcp == NULL)
		return (NULL);
	while (*(str + i))
	{
		*(strcp + i) = *(str + i);
		i++;
	}
	return (strcp);
}

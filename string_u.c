#include "main.h"

/**
 * str_leng - return the length of a given string.
 * @str: string input.
 * Return: nbr of char in str.
 */

unsigned int str_leng(char *str)
{
	unsigned int k;

	for (k = 0; str[k] != '\0'; k++)
		;
	return (k);
}

/**
 * cmp_str - compares two strings.
 * @s1: input const string
 * @s2: input const string
 * @n: input int
 * Return: returns an integer of the result of the comparison
 */
int cmp_str(const char *s1, const char *s2, int n)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{

		if (i >= n)
			break;
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}

/**
 * compare_str - compare two strings.
 * @s1: input string.
 * @s2: input string.
 * Return: returns an integer of the result of the comparison.
 */
int compare_str(const char *s1, const char *s2)
{
	int k;
	int result = 0;

	for (k = 0; s1[k] != '\0' && s2[k] != '\0'; k++)
	{
		if (s1[k] != s2[k])
		{
			result = s1[k] - s2[k];
			break;
		}
	}

	return (result);
}

/**
 * append_str - appends the src string to the dest string.
 * @dest: input string.
 * @src: input const string.
 * Return: void.
 */
char *append_str(char *dest, const char *src)
{
	char *result = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (result);
}

/**
 * copy_str - copy src to destination .
 * @dest: input char *
 * @src: input const char *
 *
 * Return: char *
 */
char *copy_str(char *dest, const char *src)
{
	int length;

	for (length = 0; src[length] != '\0'; ++length)
	{
		dest[length] = src[length];
	}
	dest[length] = '\0';
	return (dest);
}


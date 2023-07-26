#include "main.h"

/**
 * is_number - check if a string is a number.
 * @status: string to be checked
 * Return: void
 */
int is_number(const char *status)
{
	if (status == NULL || status[0] == '\0')
		return (0);
	while (*status)
	{
		if (!is_digit(*status))
			return (0);
		status++;
	}
	return (1);
}

/**
 * is_digit - check if charachter is number
 * @c: charachter
 * Return: 1 if its a digit 0 otherwise
 */
int is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * duplicate_str - returns a pointer to another space in memory.
 * which contains a copy of the string given as a parameter.
 * @str: string input.
 * Return: pointer.
 */
char *duplicate_str(const char *str)
{
	int i, length = 0;
	char *res;

	if (str == NULL)
		return (NULL);

	while (str[length] != '\0')
		length++;

	res = (char *)malloc((length + 1) * sizeof(char));

	if (res == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
		res[i] = str[i];

	return (res);
}



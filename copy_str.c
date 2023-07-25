#include "main.h"

/**
 * copy_str - copy a string.
 * @str: a given text string.
 * Return: a copy of given string.
 */
char *copy_str(char *str)
{
	int i;
	char *txtCopy;

	if (str == NULL)
		return (NULL);

	txtCopy = malloc(str_leng(str) + 1);

	if (txtCopy == NULL)
		return (NULL);

	i = 0;
	while (str[i] != '\0')
	{
		txtCopy[i] = str[i];
		i++;
	}

	txtCopy[i] = '\0';
	return (txtCopy);
}

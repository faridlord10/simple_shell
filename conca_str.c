#include "main.h"

/**
 * conca_str - concatenate two strings
 * @str1: text string.
 * @str2: txet string.
 * Return: text concatenate from str1 and str2.
 */
char *conca_str(char *str1, char *str2)
{
	int i, j;

	for (i = 0; str1[i] != '\0'; i++)
		;

	for (j = 0; str2[j] != '\0'; j++, i++)
		str1[i] = str2[j];

	str1[i] = '\0';
	return (str1);
}

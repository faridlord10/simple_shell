#include "main.h"

/**
 * length_str - length of text without equal character.
 * @str: text string.
 * Return: length of string without '='.
 */
char *length_str(char *str)
{
	int i;

	for (i = 0; str[i] != '='; i++)
		;

	return ((str + i + 1));
}

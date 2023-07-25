#include "main.h"

/**
 * str_leng - return the number of characters in string.
 * @str: is text string.
 * Return: length.
 */
unsigned int str_leng(char *str)
{
	int leng;

	if (*str == '\0')
		return (0);
	leng = 1 + str_leng(str + 1);

	return (leng);
}

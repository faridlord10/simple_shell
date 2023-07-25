#include "main.h"

/**
 * comp_str - compare two strings.
 * @txt1: text string.
 * @txt2: text string.
 * Return: 1 if are the same, 0 if else.
 */
int comp_str(char *txt1, char *txt2)
{
	int i;

	for (i = 0; txt2[i] != '\0'; i++)
	{
		if (txt1[i] != txt2[i])
			return (0);
	}
	return (1);
}

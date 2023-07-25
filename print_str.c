#include "main.h"

/**
 * print_str - print a string.
 * @str: is a array of char.
 * Return: string.
 */
void print_str(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}

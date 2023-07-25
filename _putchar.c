#include "main.h"

/**
 * _putchar - write the character to standard out.
 * @c: the char to print.
 * Return: On success 1, on error -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

#include "main.h"

/**
 * main - initialize data.
 * @argc: input size of @argv.
 * @argv: input array of command line arguments.
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	data d;
	(void)argc;
	data_initiat(&d, argv[0]);
	exec_cmd(&d);

	return (0);
}


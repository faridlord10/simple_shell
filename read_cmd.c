#include "main.h"

/**
 * read_cmd - read the command line.
 * Return: line command.
 */
char *read_cmd(void)
{
	size_t siz = 0;
	int len = 0;
	char *ligne = NULL;

	if (getline(&ligne, &siz, stdin) == -1)
	{
		free(ligne);
		exit(-1);
	}

	len = strlen(ligne);
	ligne[len - 1] = '\0';

	return (ligne);
}

#include "main.h"

/**
 * split_txt - split a given string by a delimite.
 * @ligne: given string.
 * @charactere: the delimite to divide the string by him.
 * Return: pointer of pointer.
 */
char **split_txt(char *ligne, char *charactere)
{
	char **ptr;
	int buff = 1024, i = 0;

	ptr = malloc(sizeof(char *) * buff);
	if (!ptr)
		exit(99);

	ptr[i] = strtok(ligne, charactere);
	i++;
	while (1)
	{
		ptr[i] = strtok(NULL, charactere);
		if (i >= buff)
		{
			buff += buff;
			ptr = resize_mem(ptr, buff, buff * (sizeof(char *)));
			if (!ptr)
				exit(98);
		}

		if (ptr[i] == NULL)
			break;
		i++;
	}

	return (ptr);
}

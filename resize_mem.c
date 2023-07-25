#include "main.h"

/**
 * resize_mem - reallocate memory.
 * @p: void pointer.
 * @old_taille: taille of old size in memory.
 * @new_taille: taille of new size in memory.
 * Return: null.
 */
void *resize_mem(void *p, unsigned int old_taille, unsigned int new_taille)
{
	char *nw;
	unsigned int i;

	if (p == NULL)
	{
		nw = malloc(new_taille);
		return (nw);
	}

	if (new_taille == 0 && p != NULL)
	{
		free(p);
		return (NULL);
	}

	if (new_taille == old_taille)
		return (p);

	nw = malloc(new_taille);

	if (nw == NULL)
		return (NULL);

	for (i = 0; i < old_taille; i++)
	{
		nw[i] = ((char *)p)[i];
	}
	free(p);
	return (nw);
}

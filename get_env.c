#include "main.h"

/**
 * get_env - get the path in the environ.
 * @env: global var.
 * @pathname: directory of environ.
 * Return: the path or null.
 */
char *get_env(char **env, char *pathname)
{
	char *txt, *path;
	int i, j;

	for (i = 0; env[i]; i++)
	{
		txt = malloc(1024);

		for (j = 0; env[i][j] != '='; j++)
			txt[j] = env[i][j];

		if (comp_str(txt, pathname))
		{
			path = length_str(env[i]);
			free(txt);
			return (path);
		}
		free(txt);
	}

	return (NULL);
}

#include "main.h"

/**
 * conca_path - concatenate the arguments path.
 * @str: a char.
 * @nouveau: a char.
 * Return: new path or null.
 */
char *conca_path(char **str, char **nouveau)
{
	struct stat status;
	char *sigma, **conca;
	int i, j, k;

	for (i = 0; nouveau[i]; i++)
	{
		sigma = malloc(60);
		conca_str(sigma, nouveau[i]);
		conca_str(sigma, "/");
		conca_str(sigma, str[0]);

		if (stat(sigma, &status) == 0)
		{
			for (j = 0; str[j] != (void *)0; j++)
				;
			conca = malloc(sizeof(char *) * (j + 1));
			conca[j] = NULL;
			conca[0] = copy_str(sigma);

			for (k = 1; str[k]; k++)
				conca[k] = copy_str(str[k]);
			run_cmd(conca);
			return (sigma);
		}
		free(sigma);
	}
	return (NULL);
}

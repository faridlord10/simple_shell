#include "main.h"

/**
 * get_path - get the name of path of environ.
 * @env: global var environment.
 * Return: path.
 */
char **get_path(char **env)
{
	char *find_path, **dirname, *delimite;

	delimite = ":";
	find_path = get_env(env, "PATH");
	dirname = split_txt(find_path, delimite);

	return (dirname);
}

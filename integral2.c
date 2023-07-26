#include "main.h"

/**
 * change_dir - change directory.
 * @d: data struct input.
 * Return: void.
 */
void change_dir(data *d)
{
	char *dir = d->av[1];
	char cwd[256];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		perror("getcwd() error");
	init_env(d, "PWD", cwd);
	if (!dir)
		dir = get_env_var("HOME");
	if (chdir(dir) == -1)
		perror("cd");
	else
	{
		init_env(d, "OLDPWD", get_env_var("PWD"));
		if (getcwd(cwd, sizeof(cwd)) == NULL)
			perror("getcwd() error");
		init_env(d, "PWD", cwd);
	}
}

/**
 * set_env - Set a new environment variable.
 * or modify an existing one.
 * @d: data struct input.
 * Return: void.
 */

void set_env(data *d)
{
	(void)d;
	if (d->av[1] && d->av[2])
	{
		if (init_env(d, d->av[1], d->av[2]) == -1)
		{
			perror("setenv");
		}
	}
}

/**
 * rm_env_var - Remove an environment variable.
 * @d: data struct input.
 * Return: void.
 */
void rm_env_var(data *d)
{
	int i, j;
	int len;

	(void)d;
	if (!d->av[1] || !getenv(d->av[1]))
	{
		_perror(d->programme_name, "variable not found.");
		return;
	}
	len = strlen(d->av[1]);
	for (i = 0; environ[i]; i++)
		if (strncmp(environ[i], d->av[1], len) == 0 && environ[i][len] == '=')
			for (j = i; environ[j]; j++)
				environ[j] = environ[j + 1];
}



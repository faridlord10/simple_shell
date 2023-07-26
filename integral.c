#include "main.h"

/**
 * is_builtin_exec - check if built in and then exec
 * @d: data struct input
 * Return: 1 if built in, 0 if not
 */
int is_builtin_exec(data *d)
{
	integral integral[] = {
		{"exit", exit_shell},
		{"env", curr_env},
		{"setenv", set_env},
		{"unsetenv", rm_env_var},
		{"cd", change_dir},
		{NULL, NULL},
	};
	int i;

	for (i = 0; integral[i].cmd; i++)
	{
		if (compare_str(d->av[0], integral[i].cmd) == 0)
		{
			integral[i].f(d);
			return (1);
		}
	}
	return (0);
}

/**
 * exit_shell - exits the shell.
 * @d: data struct input.
 * Return: void.
 */
void exit_shell(data *d)
{
	const char *error_String = "./hsh: 1: exit: Illegal number: ";

	if (d->av[1])
	{
		if (d->av[1][0] != '-' && is_number(d->av[1]))
			d->last_exit_stat = atoi(d->av[1]);
		else
		{
			write(STDERR_FILENO, error_String, strlen(error_String));
			write(STDERR_FILENO, d->av[1], strlen(d->av[1]));
			write(STDERR_FILENO, "\n", 1);
			d->last_exit_stat = 2;
		}
	}
	free_p_array(d->av);
	free(d->cmd);
	if (d->free_set_env)
		free_p_array(environ);
	exit(d->last_exit_stat);
}

/**
 * curr_env - prints the current environment.
 * @d: data struct input.
 * Return: void.
 */
void curr_env(data *d)
{
	int i = 0;

	(void)d;
	while (environ[i])
	{
		_printf(environ[i]);
		_printf("\n");
		i++;
	}
}


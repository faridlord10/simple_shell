#include "main.h"

/**
 * init_new_evar - Initialize a new environment variable,
 *  or modify an existing one
 * @name: variable name
 * @value: variable value
 * Return: void
 */
char *init_new_evar(char *name, char *value)
{
	size_t new_length = strlen(name) + strlen(value) + 2;
	char *new_evar = malloc(new_length);

	if (new_evar == NULL)
		return (NULL);

	strcpy(new_evar, name);
	strcat(new_evar, "=");
	strcat(new_evar, value);

	return (new_evar);
}

/**
 * get_env_var - Get the value of an environment variable.
 * @name: string input.
 * Return: value of an environment variable.
 */

char *get_env_var(char *name)
{
	int i = -1;
	size_t name_len;

	if (name == NULL || *name == '\0')
		return (NULL);
	if (environ == NULL)
		return (NULL);

	name_len = str_leng(name);

	while (environ[++i])
	{
		if (!cmp_str(environ[i], name, name_len) && environ[i][name_len] == '=')
		{
			return (environ[i] + name_len + 1);
		}
	}
	return (NULL);
}

/**
 * init_new_env - Initialize a new environment variable,
 *  or modify an existing one
 * @name: variable name
 * @value: variable value
 * Return: void
 */
char **init_new_env(char *name, char *value)
{
	int env_len = 0, i = 0;
	char *new_evar;
	char **new_environ;

	while (environ[env_len])
		env_len++;
	new_evar = init_new_evar(name, value);
	if (new_evar == NULL)
		return (NULL);
	new_environ = get_env_var(name) ? malloc((env_len + 1) * sizeof(char *))
								: malloc((env_len + 2) * sizeof(char *));

	if (!new_environ)
	{
		free(new_evar);
		return (NULL);
	}
	for (i = 0; environ[i]; i++)
	{
		new_environ[i] = malloc(strlen(environ[i]) + 1);
		if (!new_environ[i])
		{
			free_p_array(new_environ);
			free(new_evar);
			return (NULL);
		}
		if (strncmp(environ[i], name, strlen(name)) == 0
		&& environ[i][strlen(name)] == '=')
			strcpy(new_environ[i], new_evar);
		else
			strcpy(new_environ[i], environ[i]);
	}
	if (!get_env_var(name))
	{
		new_environ[env_len] = new_evar;
		new_environ[env_len + 1] = NULL;
	}
	else
		new_environ[env_len] = NULL;
	return (new_environ);
}

/**
 * locate_file_cmd - locate the executable file linked with a given command.
 * @d: string input
 * Return: void
 */
int locate_file_cmd(data *d)
{
	char *t, *path,
		*ps = malloc(str_leng(get_env_var("PATH") ? get_env_var("PATH") : "") + 1);
	int find = -1;
	size_t t_len;

	if (!get_env_var("PATH"))
		goto step_out;
	copy_str(ps, get_env_var("PATH"));
	if (ps == NULL)
		goto step_out;
	t = strtok(ps, ":");
	while (t)
	{
		t_len = str_leng(t) + str_leng(d->av[0]) + 2;
		path = malloc(t_len);
		if (path == NULL)
			return (find);
		copy_str(path, t);
		append_str(path, "/");
		append_str(path, d->av[0]);
		if (access(path, F_OK) == 0)
		{
			free(d->av[0]);
			d->av[0] = duplicate_str(path);
			free(path);
			find = 0;
			break;
		}
		free(path);
		t = strtok(NULL, ":");
	}
step_out:
	free(ps);
	return (find);
}

/**
 * init_env - Init a new env variable, or modify an existing one.
 * @d: to use the flag.
 * @name: variable name.
 * @value: variable value.
 * Return: void.
 */
int init_env(data *d, char *name, char *value)
{
	char **new_environ;

	if (!name || !value)
		return (-1);

	new_environ = init_new_env(name, value);
	if (!new_environ)
		return (-1);
	environ = new_environ;
	d->free_set_env = 1;

	return (0);
}


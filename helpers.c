#include "main.h"

/**
 * _printf - print a string to stander out put
 * @str: string input
 * Return: void
 */
void _printf(const char *str)
{
	if (!str)
		return;
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}

/**
 * free_p_array - free an array of pointers.
 * @array: array of pointers.
 * Return: void.
 */
void free_p_array(char **array)
{
	int k;

	if (!array)
		return;

	for (k = 0; array[k]; k++)
	{
		free(array[k]);
		array[k] = NULL;
	}

	free(array);
}

/**
 * split_str - split a string by delimiter.
 * @d: data struct input.
 * @delim: string input.
 * Return: void.
 */
void split_str(data *d, const char *delim)
{
	char *t;
	int num_t = 0;

	d->av = malloc(2 * sizeof(char *));
	if (d->av == NULL)
	{
		free(d->cmd);
		perror(d->programme_name);
		exit(EXIT_FAILURE);
	}
	d->av[0] = NULL;
	d->av[1] = NULL;

	t = strtok(d->cmd, delim);
	while (t)
	{
		d->av = realloc(d->av, (num_t + 2) * sizeof(char *));
		if (d->av == NULL)
			goto free;
		d->av[num_t] = duplicate_str(t);
		if (d->av[num_t] == NULL)
			goto free;
		num_t++;
		t = strtok(NULL, delim);
	}
	d->av[num_t] = NULL;
	return;
free:
	free_p_array(d->av);
	free(d->cmd);
	perror(d->programme_name);
	exit(EXIT_FAILURE);
}

/**
 * get_prompt_cmd - get commend from prompt and convert it to data struct
 * @d: data struct input
 * Return: void
 */
void get_prompt_cmd(data *d)
{
	size_t n = 0;
	ssize_t nread;
	int i = 0;

	nread = read_input_file(&d->cmd, &n, stdin);

	if (nread == -1)
	{
		free(d->cmd);
		exit(EXIT_SUCCESS);
	}

	d->cmd[nread - 1] = '\0';
	trim_str(d->cmd);
	/* replace hashtag with end of line we can also do it with strtok*/
	for (i = 0; d->cmd[i] != '\0'; i++)
	{
		if (d->cmd[0] == '#' || (d->cmd[i] == '#' && d->cmd[i - 1] == ' '))
		{
			d->cmd[i] = '\0';
			break;
		}
	}
	trim_str(d->cmd);
}

/**
 * data_initiat - init data
 * @d: data struct input
 * @programme_name: string input
 * Return: void
 */

void data_initiat(data *d, const char *programme_name)
{
	d->cmd = NULL;
	d->av = NULL;
	d->programme_name = programme_name;
	d->last_exit_stat = EXIT_SUCCESS;
	d->free_set_env = 0;
}


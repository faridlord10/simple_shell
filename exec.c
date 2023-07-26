#include "main.h"

/**
 * new_process - start a new process
 * @d: data struct input
 * Return: void
 */

void new_process(data *d)
{
	pid_t child_pid = fork();
	int status = 0;

	if (child_pid == -1)
		goto free;
	if (child_pid == 0 && execve(d->av[0], d->av, NULL) == -1)
		goto free;
	else if (wait(&status) == -1)
		goto free;
	if (WIFEXITED(status))
		d->last_exit_stat = WEXITSTATUS(status);
	return;
free:
	perror(d->programme_name);
	free_p_array(d->av);
	free(d->cmd);
	exit(EXIT_FAILURE);
}

/**
 * sign_handler - Signal handler function.
 * @signal: int input.
 * Return: void.
 */

void sign_handler(int signal)
{
	(void)signal;
	exit(EXIT_FAILURE);
}

/**
 * exec_cmd - exectute cmd.
 * @d: data struct input.
 * Return: void.
 */

void exec_cmd(data *d)
{
	const char pr[] = PROMPT;

	signal(SIGINT, sign_handler);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_printf(pr);

		get_prompt_cmd(d);
		if (str_leng(d->cmd) != 0)
		{
			split_str(d, " ");
			if (!is_builtin_exec(d))
			{
				locate_file_cmd(d);
				if (access(d->av[0], F_OK) == -1)
				{
					perror(d->programme_name);
				}
				else
				{
					new_process(d);
				}
			}
			free_p_array(d->av);
		}
		free(d->cmd);
	}
}

#include "main.h"

/**
 * rif_helper - helper function
 * @str_ptr: string input
 * @n: int input
 * Return: int
 */
int rif_helper(char **str_ptr, size_t *n)
{
	if (*str_ptr == NULL || *n == 0)
	{
		*n = 128;
		*str_ptr = malloc(*n);
		if (*str_ptr == NULL)
			return (-1);
	}
	return (0);
}

/**
 * read_input_file - reads the input from FILE
 * @str_ptr: string input
 * @n: int input
 * @stream: FILE input
 * Return: ssize_t
 */
ssize_t read_input_file(char **str_ptr, size_t *n, FILE *stream)
{
	ssize_t read_bytes = 0;
	size_t position = 0, newSize;
	static char buf[BUFF_SIZE];
	static size_t bufSize, bufPos;
	char *newBuffer;

	if (str_ptr == NULL || n == NULL || stream == NULL
		|| rif_helper(str_ptr, n) == -1)
		return (-1);
	while (1)
	{
		if (bufPos >= bufSize)
		{
			read_bytes = read(stream->_fileno, buf, BUFF_SIZE);
			if (read_bytes <= 0 && position == 0)
				return (-1);
			else if (read_bytes <= 0)
				break;
			bufSize = read_bytes;
			bufPos = 0;
		}
		if (position >= *n - 1)
		{
			newSize = *n * 2;
			newBuffer = realloc(*str_ptr, newSize);
			if (newBuffer == NULL)
				return (-1);
			*str_ptr = newBuffer;
			*n = newSize;
		}
		(*str_ptr)[position++] = buf[bufPos++];
		if ((*str_ptr)[position - 1] == '\n')
			break;
	}
	(*str_ptr)[position] = '\0';
	return (position);
}


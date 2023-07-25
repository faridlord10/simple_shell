#include "main.h"

/**
 * run_cmd - run a command.
 * @cmd: is a command to run.
 * Return: always 0.
 */
int run_cmd(char **cmd)
{
	int s;
	pid_t pd;

	pd = fork();
	if (pd == 0)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			perror(cmd[0]);
			exit(1);
		}
	}
	else if (pd > 0)
	{
		wait(&s);
	}
	else
	{
		perror("Error: ");
	}
	return (0);
}

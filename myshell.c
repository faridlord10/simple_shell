#include "main.h"

/**
 * main - the main function to run project.
 * @ac: an int.
 * @av: a char.
 * @env: global var environment.
 * Return: always 0.
 */
int main(int ac, char **av, char **env)
{
	char *ligne = NULL;
	char *delimite = "\t \a \n";
	char *command;
	char **dirname;
	(void)ac;

	dirname = get_path(env);

	signal(SIGINT, SIG_IGN);

	while (1)
	{
		ligne = read_cmd();
		av = split_txt(ligne, delimite);
		command = conca_path(av, dirname);
		if (command == NULL)
			run_cmd(av);
		free(ligne);
		free(av);
		free(command);
	}
	return (0);
}

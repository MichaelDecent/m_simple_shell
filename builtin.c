#include "shell.h"
/**
 * exit_bult - it exits the shell
 * @av: array of string
 * @readline: string of input from get input
 */
void exit_bult(char **av, char *readline)
{
	if (av[1] == NULL)
	{
		free(readline);
		free(av);
		exit(EXIT_SUCCESS);
	}
}

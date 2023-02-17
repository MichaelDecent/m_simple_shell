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
		free_all(av, readline);
		exit(EXIT_SUCCESS);
	}
}

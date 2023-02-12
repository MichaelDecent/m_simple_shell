#include "shell.h"

/**
 * main - executes the shell program
 * @ac: argument count
 * @av: an array of string argument
 */

int main(int ac, char **av)
{
	char *readline;
	int st;

	(void) ac;

	startup();

	while (1)
	{
		printf(">>>> ");

		readline = getInput();
		if (readline == NULL)
			return (-1);

		av = parser(readline);
		if (strcmp(av[0], "exit") == 0)
		{
			exit_bult(av, readline);
		}

		st = execmd(av);
		if (st == 0)
		{
			free_all(av, readline);
		}

	}
	free_all(av, readline);
	return (0);
}

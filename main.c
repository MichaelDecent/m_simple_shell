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

	startup(); /* calls my startup function*/

	while (1)
	{
		printf(">>>> "); /*prints my prompt*/

		readline = getInput(); /*reads the input passed to the shell*/
		if (readline == NULL)
			return (-1);

		av = parser(readline); /*breaks the input read into tokens*/
		
		/*checks and executes the exit builtin*/
		if (strcmp(av[0], "exit") == 0)
		{
			exit_bult(av, readline);
		}

		/*executes the command passed*/
		st = execmd(av);
		if (st == 0)
		{
			free_all(av, readline);
		}

	}
	free_all(av, readline);
	return (0);
}

#include "shell.h"
/**
 * main - executes the shell program
 * @ac: argument count
 * @av: an array of string argument
 *
 * Return: always return 1
 */
int main(int ac, char **av)
{
	char *readline;
	(void) ac;

	startup(); /* calls my startup function*/
	while (1)
	{
		printf(">>>> "); /*prints my prompt*/

		readline = getInput(); /*reads the input passed to the shell*/
		if (readline[0] == '\0')
		{
			continue;
		}
		av = parser(readline); /*breaks the input read into tokens*/
		if (av[0] == NULL)
		{
			free_all(av, readline);
			continue;
		}
		/*checks and executes the exit builtin*/
		if (strcmp(av[0], "exit") == 0)
		{
			exit_bult(av, readline);
		}
		/*checks and executes other builtins*/
		else if (check_builtin(av) == 0)
		{
			handle_builtin(av);
			free_all(av, readline);
			continue;
		}
		/*executes the command passed*/
		else
		{
			execmd(av);
		}
		free_all(av, readline);

	}
	return (1);
}
/**
 * check_builtin - checks if there is a builtin
 * @av: command passed
 *
 * Return: 0 on success and -1 on failure
 */
int check_builtin(char **av)
{
	int i;

	buil_t checks[] = {
		{"env", NULL},
		{NULL, NULL}
	};

	if (*av == NULL)
		return (-1);

	for (i = 0; checks[i].command; i++)
	{
		if (strcmp(checks[i].command, av[0]) == 0)
		{
			return (0);
		}
	}
	return (-1);
}

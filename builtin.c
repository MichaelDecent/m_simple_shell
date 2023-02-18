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

int display_env(char **av)
{
	int i;
	(void) av;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (0);
}

/**
 * handle_builtin - checks and excutes the builtins
 *
 * @readline: the commond passed
 * Returns: 0 if successful and -1 if failed
 */
int handle_builtin(char **av)
{
	int i;

	buil_t checks[] = {
		{"env", display_env},
		{NULL, NULL}
	};

	for (i = 0; checks[i].command; i++)
	{
		if (strcmp(checks[i].command, av[0]) == 0)
		{
			return (checks[i].func(av));
		}
	}
	return (-1);
}

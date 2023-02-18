#include "shell.h"
/**
 * exit_bult - it exits the shell
 * @av: array of string
 * @readline: string of input from get input
 *
 * does not return
 */
void exit_bult(char **av, char *readline)
{
	if (av[1] == NULL)
	{
		free_all(av, readline);
		exit(EXIT_SUCCESS);
	}
}
/**
 * display_env - diplays the environment variable
 * @av: an array of command passed
 *
 * Returns: 0 on success;
 */
int display_env(char **av)
{
	int i;
	(void) av;

	for (i = 0; environ[i] != NULL; i++)
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

	if (*av == NULL)
		return (1);

	for (i = 0; checks[i].command != NULL; i++)
	{
		if (strcmp(checks[i].command, av[0]) == 0)
		{
			return (checks[i].func(av));
		}
	}
	return (-1);
}

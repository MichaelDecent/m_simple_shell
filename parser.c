#include "shell.h"

/**
 * parser - it breaks a string into tokens of string
 * and stores it an array
 *
 * @readline: the string to be parsed
 */
char **parser(char *readline)
{
	char **tokens;
	char *token;
	int i;

	if (readline == NULL)
	{
		return (NULL);
	}

	tokens = malloc(sizeof(char *) * 1024);
	if (!tokens)
	{
		perror("malloc failed");
		return (NULL);
	}

	token = strtok(readline, " \n");

	i = 0;
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}

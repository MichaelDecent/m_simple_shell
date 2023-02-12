#include "shell.h"
/**
 * getInput - gets the input passed to the shell
 *
 * Return: the input entered
 */

char *getInput(void)
{
	char *input = NULL;
	size_t input_size = 0;

	if (getline(&input, &input_size, stdin) == -1)
	{
		perror("Error: Exiting the shell...");
		free(input);
		return (NULL);
	}
	return (input);

}

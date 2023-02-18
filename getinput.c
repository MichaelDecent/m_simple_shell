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

	/*reads line passed to the shell, and checks failure of getline function*/
	if (getline(&input, &input_size, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Error: Exiting the shell...");
			free(input);
			exit(EXIT_FAILURE);
		}
	}
	return (input);

}

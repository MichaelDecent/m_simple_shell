#include "shell.h"
/**
 * execmd - it executes a function
 * @av: an array of strings
 *
 * Return: -1 if failed
 */
int execmd(char **av)
{
	char *command = NULL;
	pid_t pid;
	int status;

	if (av)
	{
		command = getpath(av[0]);
		if (command != NULL)
		{
			pid = fork();
			if (pid == -1)
			{
				perror("Error");
					return (-1);
			}
			else if (pid == 0)
			{

				if (execve(command, av, NULL) == -1)
				{
					perror("Error");
					free(command);
					free(av);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(&status);
				free(command);
			}
		}
		else
			perror("Error: invalid command");
	}
	return (0);
}
/**
 * getpath - handles the PATH of a command
 * @cmd: the command
 *
 * Return: the path to the command if fails NULL
 */
char *getpath(char *cmd)
{
	char *pathname;
	char *pathtoken;
	char *file_path;
	char *file_path_cpy;
	struct stat stat_buf;
	int token_len;

	file_path = getenv("PATH");
	if (file_path)
	{
		file_path_cpy = strdup(file_path);
		pathtoken = strtok(file_path_cpy, ":");
		while (pathtoken != NULL)
		{
			token_len = strlen(pathtoken);
			pathname = malloc(token_len + strlen(cmd) + 2);
			if (pathname == NULL)
			{
				perror("Error");
				return (NULL);
			}
			strcpy(pathname, pathtoken);
			strcat(pathname, "/");
			strcat(pathname, cmd);
			strcat(pathname, "\0");
			if (stat(pathname, &stat_buf) == 0)
			{
				free(file_path_cpy);
				return (pathname);
			}
			free(pathname);
			pathtoken = strtok(NULL, ":");
		}
		free(file_path_cpy);
		if (stat(cmd, &stat_buf) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	return (NULL);
}

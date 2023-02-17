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
		command = getpath(av[0]); /*handles the PATH, generates the path to the executable*/
		if (command != NULL)
		{
			/*creating a child process*/
			pid = fork();
			if (pid == -1)
			{
				perror("Error");
					return (-1);
			}
			else if (pid == 0)
			{
				/*executing the command and checking for the failure of execve function*/
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
				/*calling wait function to avoid zombie process*/
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
 * Return: the path to the command and  NULL if failed.
 */
char *getpath(char *cmd)
{
	char *pathname;
	char *pathtoken;
	char *file_path;
	char *file_path_cpy;
	struct stat stat_buf;
	int token_len;

	/*getting the content of enviroment variable "PATH" */
	file_path = getenv("PATH");
	if (file_path)
	{
		file_path_cpy = strdup(file_path); /*dulicate the file_path*/
		pathtoken = strtok(file_path_cpy, ":"); /*tokenizing file_path*/
		/*building a file_path and checks whether it exists*/
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
			if (stat(pathname, &stat_buf) == 0) /*checks if file path exists*/
			{
				free(file_path_cpy);
				return (pathname);
			}
			free(pathname);
			pathtoken = strtok(NULL, ":");
		}
		free(file_path_cpy);
		if (stat(cmd, &stat_buf) == 0) /*finally checks if command passed is a filepath*/
		{
			return (cmd);
		}
		return (NULL);
	}
	return (NULL);
}

#ifndef SHELL_H
#define SHELL_H


/**###### LIBRARIES USED #####*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>



void startup(void);
char *getInput(void);
char **parser(char *readline);
int execmd(char **av);
void free_all(char **av, char *readline);
char *getpath(char *cmd);
void exit_bult(char **av, char *readline);
int handle_builtin(char **av);
int display_env(char **av);
int check_builtin(char **av);

/* Clear the shell using escape sequence */
#define clear() printf("\033[H\033[J")



/**###### ENVIRON #####*/
extern char **environ;

typedef struct builtins
{
	char *command;
	int (*func)(char **av);
} buil_t;
#endif

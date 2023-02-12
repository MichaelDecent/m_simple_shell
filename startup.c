#include "shell.h"

/**
 * startup - Greeting shell during startup
 *
 */
void startup(void)
{
	char *username;

	clear();

	printf("\n\n\n\n******************************************");
	printf("\n\n\n\t****SHELL****");
	printf("\n\n\t===================");
	printf("\n\n\n\n******************************************");

	username = getenv("USER");

	printf("\n\n\n Welcome %s!", username);
	printf("\n");

	sleep(2);
	clear();
}

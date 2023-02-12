#include "shell.h"

/**
 * free_all - Free Array Of Char Pointer And Char Pointer
 * @av:Array Pointer
 * @readline:Char Pointer
 * Return: Void
 */
void free_all(char **av, char *readline)
{
	free(av);
	free(readline);
	readline = NULL;
	av = NULL;
}

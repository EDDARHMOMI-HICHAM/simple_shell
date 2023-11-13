#include "shell.h"

/**
 * print_env - Prints the environment variables.
 * Return: void
 */


void print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}


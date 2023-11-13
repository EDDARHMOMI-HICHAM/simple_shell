#include "shell.h"

/**
 * print_env - Prints the environment variables.
 *
 * This function iterates through the environment variables
 * and prints each variable along with its value to the standard output.
 */

/*extern char **environ;*/

void print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}


#include "shell.h"

/**
 * change_dir - a function that changes the current directory to the specified
 * @cmd: the user input
 * Return: int
 */


int change_dir(char *cmd)
{
	if (cmd == NULL)
	{
		printf("Usage: cd <directory>\n");
		return (1);
	}

	if (access(cmd, F_OK) != 0)
	{
		printf("Directory does not exist.\n");
		return (1);

	}

	if (chdir(cmd) != 0)
	{
		printf("Failed to change directory.\n");
		return (1);

	}

	return (0);
}

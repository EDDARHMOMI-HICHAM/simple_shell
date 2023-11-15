#include "shell.h"

/**
 * change_dir - a function that changes the current directory to the specified
 * @cmd: the user input
 * Return: int
 */


int change_dir(char *cmd)
{
	if (cmd == NULL || strcmp(cmd, "~") == 0)
	{
		if (chdir(getenv("HOME")) != 0)
		{
			printf("Failed to change directory to home.\n");
			return (1);
		}
		return (0);
	}

	else if (access(cmd, F_OK) != 0)
	{
		printf("Directory does not exist.\n");
		return (1);

	}

	else if (chdir(cmd) != 0)
	{
		printf("Failed to change directory.\n");
		return (1);

	}

	return (0);
}

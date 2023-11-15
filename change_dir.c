#include "shell.h"

/**
 * change_dir - a function that changes the current directory to the specified
 * @cmd: the user input
 * Return: int
 */


int change_dir(char *cmd)
{
	char *cwd = getcwd(NULL, 0);

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
		printf("cd: %s: No such file or directory.\n ", cmd);
		return (1);

	}

	else if (chdir(cmd) != 0)
	{
		printf("Failed to change directory.\n");
		return (1);
	}

	if (cwd == NULL)
	{
		printf("Failed to get current working directory.\n");
		return (1);
	}


	free(cwd);
	return (0);
}

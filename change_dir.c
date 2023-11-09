#include "shell.h"

/**
 * change_dir - a function that changes the current directory to the specified
 * @cmd: the user input
 * Return: int
 */


int change_dir(char *cmd)
{
	char **tokens = tokenize_cmd(cmd);

	if (strcmp(tokens[0], "cd") == 0)
	{
		if (tokens[1] == NULL)
		{
			printf("Usage: cd <directory>\n");
			return (1);
		}

		if (access(tokens[1], F_OK) != 0)
		{
			printf("Directory does not exist.\n");
			return (1);
		}

		if (chdir(tokens[1]) != 0)
		{
			printf("Failed to change directory.\n");
			return (1);
		}
		return (0);
	}
	return (0);
}

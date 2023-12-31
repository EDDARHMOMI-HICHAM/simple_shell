#include "shell.h"

/**
 * check_token - A function that checks the user input for special command
 * @tokens: an array of commands provided by the user
 * @argv: an array of strings representing the command-line arguments
 * Return: void
 */

int check_token(char **tokens, char *argv[])
{
	char *full_path;
	int status = 0;

	if (strcmp(tokens[0], "env") == 0)
		print_env();
	else if (strcmp(tokens[0], "cd") == 0)
		change_dir(tokens[1], argv);
	else if (strcmp(tokens[0], "setenv") == 0)
	{
		if (tokens[1] == NULL)
			return (-1);
		status = _setenv(tokens[1], tokens[2]);
	}
	else if (strcmp(tokens[0], "unsetenv") == 0)
		status = _unsetenv(tokens[1]);
	else
	{
		full_path = search_path(tokens[0]);
		status = exec_cmd(tokens, full_path, argv);
		if (full_path != NULL)
			free(full_path);
	}
	return (status);
}

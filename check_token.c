#include "shell.h"

/**
 * check_token - A function that checks the user input for special command
 * @tokens: an array of commands provided by the user
 * @argv: an array of strings representing the command-line arguments
 * Return: void
 */

void check_token(char **tokens, char *argv[])
{
	char *full_path;

	if (strcmp(tokens[0], "env") == 0)
		print_env();
	else if (strcmp(tokens[0], "cd") == 0)
		change_dir(tokens[1]);
	else
	{
		full_path = search_path(tokens[0]);
		exec_cmd(tokens, full_path, argv);
		free(full_path);
	}
}

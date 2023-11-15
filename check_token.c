#include "shell.h"

/**
 * check_token - A function that checks the user input for special command
 * @tokens: an array of commands provided by the user
 * Return: void
 */

void check_token(char **tokens)
{
	char *full_path;

	if (strcmp(tokens[0], "env") == 0)
		print_env();
	
	else if (strcmp(tokens[0], "cd") == 0)
		change_dir(tokens[1]);
	else if (strcmp(tokens[0], "cd") == 1)
		printf("%s: %s: No such file or directory.\n ",tokens[0],tokens[1]);
	else
	{
		                printf("%s: %s: No such file or directory.\n ",tokens[0],tokens[1]);

		full_path = search_path(tokens[0]);
		exec_cmd(tokens, full_path);
	}
	free(full_path);
}

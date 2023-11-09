#include "shell.h"

/**
*  exit_shs - exit the our shell handling 
* @cmd: A pointer to an argument.
* Return: zero after finishing the handling .
*/

int exit_shs(char *cmd)
{
	char **tokens;
	int status;
	char *full_path;
	char *cmd_copy;


	if (cmd == NULL || cmd[0] == '\0')
		return (0);

	cmd_copy = strdup(cmd);
	tokens = tokenize_cmd(cmd);
	if (strcmp(tokens[0], "exit") == 0)
	{
		free(tokens[0]);
		free(tokens);
		free(cmd);
		free(cmd_copy);
		exit(0);
	}
	full_path = search_path(tokens[0]);

	status = exec_cmd(tokens, full_path, cmd_copy);
	if (status != 0)
	{
		printf("Error executing command.\n");
	}
	free(tokens[0]);
	free(tokens);
	free(cmd_copy);

	return (0);
}


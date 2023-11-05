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

	while (1)
	{
		if (cmd == NULL) {
			printf("\n");
			break;
		}

		tokens = tokenize_cmd(cmd);

		if (strcmp(tokens[0], "exit") == 0) {
			break;
		}

		status = exec_cmd(tokens);
		if (status != 0) {
			printf("Error executing command.\n");
		}

		free(cmd);
		free(tokens);
	}

	return (0);
}


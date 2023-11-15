#include "shell.h"

int exit_shs(char *cmd){
	char **tokens;
	int status;
	char *full_path;
	int exit_status = 0;
	
	if (cmd == NULL || cmd[0] == '\0')
		return (0);
	
	tokens = tokenize_cmd(cmd);
	full_path = search_path(tokens[0]);
	
	if (strcmp(tokens[0], "exit") == 0)
	{
		if (tokens[1])
			exit_status = atoi(tokens[1]);
	
		free(tokens);
		exit(exit_status);
	}
	else
	{
		full_path = search_path(tokens[0]);
		status = exec_cmd(tokens, full_path);
		if (status != 0)
			printf("Error executing command.\n");

		free(tokens);
	}
	
	return (0);
}


#include "shell.h"

/**
*  exec_cmd - execute a command with arguments and wait for it to finish.
* @cmd: A double pointer to an array of commands and arguments.
* @cmd_path: the path to the command
* @argv: an array of strings representing the command-line arguments
* Return: zero after finishing execution.
*/


int exec_cmd(char **cmd, char *cmd_path, char *argv[])
{
	char **env = environ;
	pid_t child = fork();
	int status;

	if (cmd_path == NULL)
		cmd_path = cmd[0];
	if (child == 0)
	{
		execve(cmd_path, cmd, env);
		fprintf(stderr, "%s: 1: %s: not found", argv[0], cmd[0]);
		exit(EXIT_FAILURE);
	}
	else if (child < 0)
	{
		perror("fork");
		return (-1);
	}
	else
	{
		waitpid(child, &status, 0);

	}

	return (0);
}


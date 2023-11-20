
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
	pid_t child = 0;
	int status;
	printf("print cmd: %s\n", cmd_path);
	if (cmd_path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", argv[0], cmd[0]);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		execve(cmd_path, cmd, env);
		return (2);
	}
	else if (child < 0)
	{
		perror("fork");
		return (-1);
	}
	else
	{
		waitpid(child, &status, 0);
		status =  WIFEXITED(status) ? WEXITSTATUS(status) : -1;

	}

	return (status);
}



#include "shell.h"

/**
*  exec_cmd - execute a command with arguments and wait for it to finish.
* @cmd: A double pointer to an array of commands and arguments.
* Return: zero after finishing execution.
*/


int exec_cmd(char **cmd, char *cmd_path)
{
	pid_t child = fork();
	if (cmd_path == NULL)
		cmd_path = cmd[0];
	if (child == 0)
	{
		execve(cmd_path, cmd, NULL);
		perror(cmd[0]);
		exit(1);
	}
	else if (child < 0)
	{
		perror("fork");
		return (-1);
	}
	else
	{
		waitpid(child, NULL, 0);
	}

	return (0);
}


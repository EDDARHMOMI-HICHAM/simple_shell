
#include "shell.h"

/**
*  exec_cmd - execute a command with arguments and wait for it to finish.
* @cmd: A double pointer to an array of commands and arguments.
* @cmd_path: the path to the command
* Return: zero after finishing execution.
*/


int exec_cmd(char **cmd, char *cmd_path)
{
	char **env = environ;
	pid_t child = fork();
	int status;

	if (cmd_path == NULL)
		cmd_path = cmd[0];
	if (child == 0)
	{
		execve(cmd_path, cmd, env);
		write(STDERR_FILENO, cmd[0], _strlen(cmd[0]));
		write(STDERR_FILENO, ": command not found\n", 20);
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


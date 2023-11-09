
#include "shell.h"

/**
*  exec_cmd - execute a command with arguments and wait for it to finish.
* @cmd: A double pointer to an array of commands and arguments.
* Return: zero after finishing execution.
*/


int exec_cmd(char **cmd, char *cmd_path, char *cmd_copy)
{
	/** check for pipe */
	if (strstr(cmd_copy, "|") != NULL)
	{
		int pipefd[2];
		pid_t child1, child2;
		if (pipe(pipefd) == -1)
		{
			perror("pipe");
			return (1);
		}
		
		child1 = fork();
		if (child1 == 0) {
                	/* Child process 1 */
			close(pipefd[0]);
			dup2(pipefd[1], STDOUT_FILENO);
                	close(pipefd[1]);
			/* Execute the first command */
			execvp(command[0], command);
			perror("execvp");
			return (1);
		}
		else
		{
			child2 = fork();
			if (child2 == 0)
			{
				close(pipefd[1]);
				dup2(pipefd[0], STDIN_FILENO);
				close(pipefd[0]);
				/* Execute the second command */
				execvp(command[i + 1], command + i + 1);
				perror("execvp");
				return (1);
			}
			else
			{
				/* Parent process */
				close(pipefd[0]);
				close(pipefd[1]);
				wait(NULL);
				wait(NULL);
			}
		}
	}
	else
	{
		/** no pipe */
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

	}
	return (0);
}


#include "shell.h"

/**
 * _readline - A function that reads from the stdin
 * @nread: a pointer to update the no of chars read
 * @cmd: the input from the user
 * @file: the file to read from, stdin or redirected
 * Return: returns the arrays of chars read
 */

void _readline(char *cmd, int *nread, FILE *file)
{
	if (file == NULL)
	{
		*nread = read(STDIN_FILENO, cmd, 1024);
		if (*nread < 0)
		{
			perror("Error reading from stdin");
			exit(EXIT_FAILURE);
		}
	} else
	{
		if (fgets(cmd, 1024, file) == NULL)
		{
			*nread = 0;
			if (file != stdin)
			{
				write(STDOUT_FILENO, "\n", 1);
				exit(EXIT_SUCCESS);
			}
			return;
		}
		*nread = strlen(cmd);
	}
	if (*nread == 0)
	{
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	cmd[*nread - 1] = '\0';

}

#include "shell.h"

/**
 * _readline - A function that reads from the stdin
 * @nread: a pointer to update the no of chars read
 * @cmd: the input from the user
 * Return: returns the arrays of chars read
 */

void _readline(char *cmd, int *nread)
{
	*nread = read(STDIN_FILENO, cmd, 1024);
	if (*nread < 0)
	{
		printf("Exiting the shell\n");
		exit(EXIT_FAILURE);
	}
	else if (*nread == 0)
	{
		printf("Exiting the shell EOF\n");
		exit(EXIT_SUCCESS);
	}
	cmd[*nread - 1] = '\0';

}

#include "shell.h"



void readline(size_t *num_chars, char *line)
{
	int n;

	n = read(STDIN_FILENO, line, 1024);
	if (n == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	else
	{
		line[n - 1] = '\0';
		*num_chars = n - 1;
	}
}

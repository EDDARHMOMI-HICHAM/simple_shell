#include "main.h"



char *readline(size_t *num_chars)
{
	size_t n;
	char *buffer = malloc(1024);

	if (buffer == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	n = read(STDIN_FILENO, buffer, 1024);
	if (n == -1)
	{
		perror("read");
		free(buffer);
		return (NULL);
	}
	buffer[n - 1] = '\0';
	*num_chars = n - 1;
	return (buffer);
}

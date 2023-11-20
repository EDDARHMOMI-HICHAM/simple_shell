#include "shell.h"

/**
 * check_source - A function that checks the source of an input
 * @argc: int argurement count
 * @fd: file descriptor
 * @argv: pointer to argurement count
 * @sig: int flag for input type (0 or 1)
 * Return: pointer to FILE or NULL on no input
 */


FILE *check_source(int argc, int fd, char **argv, int *sig)
{
	FILE *file;

	if (argc == 2)
	{
		file = fopen(argv[1], "r");
		if (file == NULL)
		{
			*sig = 0;
			fprintf(stderr, "%s: 0: Can't open %s\n", argv[0], argv[1]);
			exit(127);
		}
		*sig = 1;
	}
	else if (!isatty(fd))
		file = stdin;
	else
		file = NULL;
	return (file);

}

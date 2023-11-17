#include "shell.h"

#define MAX_LINE 1024

/**
 * execute_from_f - executes commands from a file.
 *
 * @filename: The name of the file containing the commands.
 *
 * Return: 0 if all's good, else 1.
 */

int execute_from_f(char *filename)
{
	char line[MAX_LINE];
	FILE *fp = fopen(filename, "r");
	int status = system(line);

	if (!fp)
	{
		perror("fopen");
		return (1);
	}

	while (fgets(line, MAX_LINE, fp))
	{
		line[strlen(line) - 1] = '\0';

		if (status != 0)
		{
			fprintf(stderr, "Error executing command '%s': %d\n", line, status);
		}
	}
	fclose(fp);

	return (0);
}

#include "shell.h"

/**
 * main - The entrance to our simple shell program
 * @argc: the argurement count
 * @argv: the argurement array list
 * Return: 0 on success any number on failure
 */


int main(int argc, char *argv[])
{
	size_t num = 0;
	char *line;
	int sh = 1;
	char **tokens;
	int i;

	(void) argc;
	(void) argv;
	while (sh)
	{
		prompt();
		line = readline(&num);
		tokens = tokenize_cmd(line);
		exec(tokens);
		for (i = 0; tokens[i] != NULL; i++)
		{
			printf("%s\n", tokens[i]);
			free(tokens[i]);
		}
		free(tokens);
		free(line);
	}
	free(line);
	return (0);
}

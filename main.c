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
	char *line = malloc(sizeof(char) * 1024);
	int sh = 1;
	char **tokens;
	int i;

	(void) argc;
	(void) argv;
	while (sh)
	{
		prompt();
		readline(&num, line);
		tokens = tokenize_cmd(line);
		if (strcmp(tokens[0], "exit") == 0)
		{
			free(line);
			free(tokens[0]);
			free(tokens);
			return (0);
		}
	/**	exec(tokens); */
		for (i = 0; tokens[i] != NULL; i++)
		{
			printf("%s\n", tokens[i]);
			free(tokens[i]);
		}
		free(tokens);
	}
	free(line);
	return (0);
}

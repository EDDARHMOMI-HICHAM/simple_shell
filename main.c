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

	(void) argc;
	(void) argv;
	while (sh)
	{
		prompt();
		readline(&num, line);
		exit_shs(line);
	/*	change_dir(line); */
	}
	free(line);
	return (0);
}

#include "shell.h"

/**
 * main - The entrance to our simple shell program
 * @argc: The number of argurements
 * @argv: The array of argurements
 * @env: the environment variables
 * Return: (0) on success any number on error
 */

int main(int argc, char *argv[], char *env[])
{
	char cmd[1024], prompt[] = "$ ";
	int nread = 0, fd = fileno(stdin), status = 0 /*pipe = 1 i = 0*/;
	char *cmd_copy;
	char **tokens;
	FILE *file;
	(void) env;

	if (argc == 2)
		file = fopen(argv[1], "r");
	else if (!isatty(fd))
		file = stdin;
	else
		file = NULL;
	while (1)
	{
		if (file == NULL)
			write(STDOUT_FILENO, prompt, sizeof(prompt));
		_readline(cmd, &nread, file);
		if (nread == 0)
			break;
		if (cmd == NULL)
			continue;
		rem_space(cmd);
		if (cmd[0] == '\0')
			continue;
		cmd_copy = strdup(cmd);
		tokens = tokenize_cmd(cmd);
		if (strcmp(tokens[0], "exit") == 0)
		{
			free_tokens(tokens);
			free(cmd_copy);
			exit(EXIT_SUCCESS);
		}
		status = check_token(tokens, argv);
		free_tokens(tokens);
		free(cmd_copy);
	}

	return (status);
}

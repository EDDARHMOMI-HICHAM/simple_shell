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
	int nread = 0, fd = fileno(stdin), pipe = 1;
	char *cmd_copy, *full_path;
	char **tokens;
	(void) argc, (void) argv, (void) env;

	while (1 && pipe)
	{
		write(STDOUT_FILENO, prompt, sizeof(prompt));
		_readline(cmd, &nread);

		if (cmd == NULL || cmd[0] == '\0')
			continue;

		if (strcmp(tokens[0], "env") == 0)
			print_env();

		if (!isatty(fd))
		{
			fflush(stdin);
			pipe = 0;
		}
		cmd_copy = strdup(cmd);
		tokens = tokenize_cmd(cmd);
		if (strcmp(tokens[0], "exit") == 0)
		{
			free(tokens[0]);
			free(tokens);
			free(cmd_copy);
			exit(EXIT_SUCCESS);
		}

		 if (strcmp(tokens[0], "cd") == 0)
		 {
			change_dir(tokens[1]);
			continue;
		 }
		full_path = search_path(tokens[0]);
		exec_cmd(tokens, full_path);
		free(tokens[0]);
		free(tokens);
		free(cmd_copy);
	}
	return (0);
}

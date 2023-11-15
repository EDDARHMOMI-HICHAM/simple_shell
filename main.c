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
	int nread = 0, fd = fileno(stdin) /*pipe = 1*/;
	char *cmd_copy;
	char **tokens;
	FILE *file;
	(void) argc, (void) argv, (void) env;

	if (!isatty(fd))
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
			if (cmd == NULL || cmd[0] == '\0')
				continue;
			cmd_copy = strdup(cmd);
			tokens = tokenize_cmd(cmd);
			if (strcmp(tokens[0], "exit") == 0)
			{
				free(tokens[0]);
				free(tokens);
				free(cmd_copy);
				exit(EXIT_SUCCESS);
			}
			check_token(tokens);
			free(tokens[0]);
			free(tokens);
			free(cmd_copy);
	}
	return (0);
}

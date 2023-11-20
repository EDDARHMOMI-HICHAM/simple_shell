#include "shell.h"

/**
 * exit_param - Convert a string to an integer and perform checks.
 * @cmd: The input string.
 * @argv: pointer to cmd argurment
 * Return: The converted integer or an error code.
 */

int exit_param(char *cmd, char *argv)
{
	int i, cmd_num;

	if (cmd == NULL)
		return (0);
	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] < '0' || cmd[i] > '9')
		{
			fprintf(stderr, "%s: 1: exit: Illegal number: %s\n", argv, cmd);
			return (2);
		}
	}

	cmd_num = atoi(cmd);
	if (cmd_num > 256)
		return (232);
	else
		return (cmd_num);
}

/**
 * main - The entrance to our simple shell program
 * @argc: The number of argurements
 * @argv: The array of argurements
 * Return: (0) on success any number on error
 */


int main(int argc, char *argv[])
{
	char cmd[1024], prompt[] = "$ ";
	int nread = 0, fd = fileno(stdin), status = 0, sig = 0;
	char *cmd_copy, **tokens;
	FILE *file;

	file = check_source(argc, fd, argv, &sig);
	while (1)
	{
		if (file == NULL)
			write(STDOUT_FILENO, prompt, sizeof(prompt));
		_readline(cmd, &nread, file, sig);
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
			if (tokens[1] != NULL)
				status = exit_param(tokens[1], argv[0]);
			free_tokens(tokens);
			free(cmd_copy);
			exit(status);
		}
		status = check_token(tokens, argv);
		free_tokens(tokens);
		free(cmd_copy);
	}

	return (status);
}

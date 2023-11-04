#include "shell.h"

/**
 * tokenize_cmd -  Tokenizes a command string.
 *
 * @cmd: The command string to tokenize.
 *Return: An array of strings, where each string is a token from the command.
 */

char **tokenize_cmd(char *cmd)
{

	int nb = 0;
	char **tokens;
	int count = 0;
	char del[] = " \t\n";
	char *token_copy = NULL;
	char *cmd_copy = strdup(cmd);

	token_copy = strtok(cmd_copy, del);
	while (token_copy != NULL)
	{
		nb++;
		token_copy = strtok(NULL, del);
	}
	tokens = malloc(sizeof(char *) * (nb + 1));

	char *token = strtok(cmd, del);

	while (token != NULL)
	{
	tokens[count] = strdup(token);
		count++;
		token = strtok(NULL, del);
	}
	tokens[count] = NULL;
	free(cmd_copy);
	return (tokens);
}

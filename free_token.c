#include "shell.h"

/**
 * free_tokens - a function that frees the tokens after usuage
 * @tokens: pointer to arrays of tokens
 * Return: void
 */



void free_tokens(char **tokens)
{
	int i;

	for (i = 0; tokens[i] != NULL; ++i)
	{
		free(tokens[i]);
	}
	free(tokens);
}


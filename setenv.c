#include "shell.h"

/**
 * _setenv - A function that sets or update new environment variable
 * @param: a string key
 * @value: the value
 * Return: int
 */

int _setenv(char *param, char *value)
{
	int i, j;
	char *new_param;

	if (param == NULL || value == NULL)
	{
		fprintf(stderr, "Invalid arguments for setenv\n");
		return (-1);
	}

	new_param = malloc(_strlen(param) + _strlen(value) + 2);
	if (new_param == NULL)
	{
		fprintf(stderr, "Memory Allocation fails");
		return (-1);
	}

	for (i = 0; param[i] != '\0'; i++)
		new_param[i] = param[i];
	new_param[i] = '=';

	for (j = 0; value[j] != '\0'; j++, i++)
		new_param[i] = value[j];
	new_param[i] = '\0';

	if (putenv(new_param) != 0)
	{
		fprintf(stderr, "Failed to set environment variable %s\n", param);
		free(new_param);
		return (-1);
	}
	free(new_param);
	return (0);
}


/**
 * _unsetenv - A function that unset an environment value
 * @param: the param to unset
 * Return: 0 on success or -1 if error
 */

int _unsetenv(char *param)
{
	if (param == NULL)
	{
		perror(param);
		return (-1);
	}
	if (unsetenv(param) != 0)
	{
		perror(param);
		return (-1);
	}
	return (0);
}

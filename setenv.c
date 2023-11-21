#include "shell.h"

/**
 * _setenv - A function that sets or update new environment variable
 * @params: a string key
 * Return: int
 */

int _setenv(char *param, char *value)
{

	if (param == NULL || value == NULL)
	{
		fprintf(stderr, "Invalid arguments for setenv\n");
		return (-1);
	}

	if (setenv(param, value, 1) != 0)
	{
		fprintf(stderr, "Failed to set environment variable %s\n", param);
		return (-1);
	}
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

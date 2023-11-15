#include "shell.h"


/**
 * file_exists - a function that checks if an exectable exist in a directory
 * @path: a const path
 * Return: int
 */


int file_exists(char *path)
{
	struct stat buffer;

	return (stat(path, &buffer) == 0);
}

/**
 * search_path - A function that searches the environ path for an executable
 * @cmd: the command
 * Return: returns the path to the executable
 */

char *search_path(char *cmd)
{
	char *path_env = NULL;
	char *path = NULL;
	char *token = NULL;
	char *full_path;

	path_env = getenv("PATH");
	if (!path_env)
	{
		return (NULL);
	}

	path = strdup(path_env);
	if (!path)
	{
		perror("strdup");
		return (NULL);
	}

	token = strtok(path, ":");
	while (token != NULL)
	{
		full_path = malloc(_strlen(token) + _strlen(cmd) + 2);
		if (full_path)
		{
			sprintf(full_path, "%s/%s", token, cmd);
			if (file_exists(full_path))
			{
				free(path);
				return (full_path);
			}
			free(full_path);
		}
		token = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}

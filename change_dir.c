#include "shell.h"

/**
 * change_dir - a function that changes the current directory to the specified
 * @cmd: the user input
 * @argv: pointer to array of strings of cmd line argurement
 * Return: int
 */


int change_dir(char *cmd, char **argv)
{
	char c_wdir[1024], tmp[1024];

	getcwd(c_wdir, sizeof(c_wdir));

	if (cmd == NULL || strcmp(cmd, "~") == 0)
	{
		if (chdir(getenv("HOME")) != 0 || (chdir(getenv("HOME")) != 0) != 0)
		{
			perror(cmd);
			return (1);
		}
	}

	else if (strcmp(cmd, "-") == 0)
	{
		if (chdir(getenv("OLDPWD")) != 0)
		{
			perror(cmd);
			return (1);
		}
		if (getcwd(tmp, sizeof(tmp)) != NULL)
			fprintf(stdout, "%s\n", tmp);
		return (0);
	}
	else if (access(cmd, X_OK | R_OK) == -1)
	{
		fprintf(stderr, "%s: 1: cd: can't cd to %s\n", argv[0], cmd);
		return (1);

	}
	else if (chdir(cmd) != 0)
	{
		perror(cmd);
		return (1);
	}
	_setenv("OLDPWD", c_wdir);
	getcwd(c_wdir, sizeof(c_wdir));
	_setenv("PWD", c_wdir);

	return (0);
}

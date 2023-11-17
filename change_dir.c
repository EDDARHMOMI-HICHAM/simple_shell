#include "shell.h"

/**
 * change_dir - a function that changes the current directory to the specified
 * @cmd: the user input
 * Return: int
 */


int change_dir(char *cmd)
{
	char c_wdir[200];
	char n_wdir[200];

	getcwd(c_wdir, sizeof(c_wdir));

	if (cmd == NULL || strcmp(cmd, "~") == 0)
	{
		if (chdir(getenv("HOME")) != 0)
		{
			perror("Failed to change directory to home");
			return (1);
		}
	}

	else if (access(cmd, F_OK) != 0)
	{
		perror("Directory does not exist");
		return (1);

	}
	else if (chdir(cmd) != 0)
	{
		perror("Failed to change directory");
		return (1);
	}
	getcwd(n_wdir, sizeof(n_wdir));
	_setenv("OLDPWD", c_wdir);
	_setenv("PWD", n_wdir);

	return (0);
}

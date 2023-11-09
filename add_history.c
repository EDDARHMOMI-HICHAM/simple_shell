#include "shell.h"

/**
 * add_history - add the commands to the history
 *@cmd: the command from the user
 * Return : nothing.
 */

void  add_history(char *cmd)
{
	char history[LAST_ENTERD][1024];
	int i = 0;

	if (i < LAST_ENTERD)
	{
		strcpy(history[i], cmd);
		i++;
	}
}

#include "shell.h"

/**
 * add_history - add the commands to the history
 *@cmd: the command from the user
 * Return : nothing.
 */

void  add_history(char *cmd)
{
	char history[LAST_ENTERD][1024];
	int i;

	if (i < LAST_ENTERD)
	{
		strcpy(strcpy(history[i], cmd);
		i++;
	}
}

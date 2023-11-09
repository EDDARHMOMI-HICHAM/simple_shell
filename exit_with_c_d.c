#include "shell.h"


void handle_ctrl_d(void)
{
	printf("\nExiting shell.\n");
	exit(0);
}

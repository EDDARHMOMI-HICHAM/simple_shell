#include "shell.h"

/**
 * prompt - A function that prints the shell prompt
 * Return: void
 */

void prompt(void)
{
        char *prompt = "$ ";

        write(STDOUT_FILENO, prompt, _strlen(prompt));
}


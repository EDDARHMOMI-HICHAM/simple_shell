#include "shell.h"
#include <ctype.h>


/**
 * rem_space - A function that checks if a given string is empty
 * @str: pointer to the string
 * Return: 1 if empty or 0 if otherwise
 */

void rem_space(char *str)
{
	int i, j;

	for (i = 0; str[i] && isspace((unsigned char)str[i]); i++)
		;
	for (j = 0; str[i]; i++, j++)
		str[j] = str[i];
	str[j] = '\0';
}

#include "shell.h"

/**
 * _strlen - Calculate the length of a string.
 * @str: A pointer to a string.
 * Return: The length of the string.
 */

int _strlen(char *str)
{
	if (*str == '\0')
		return (0);
	return (1 + _strlen(str + 1));
}

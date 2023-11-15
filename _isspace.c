#include "shell.h"

/**
 * _isspace - A function that checks if a given string is empty
 * @str: pointer to the string
 * Return: 1 if empty or 0 if otherwise
 */

int _isspace(char str)
{
	if (str != ' ')
		return (1);
	return (0);
}

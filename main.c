#include "shell.h"

/**
 * main - The entrance to our simple shell program
 * argc: the argurement count
 * argv: the argurement array list
 * Return: 0 on success any number on failure
 */


int main(int argc, char *argv[])
{
        size_t num = 0;
        char *line;	
        int sh = 1;

        while (sh)
        {
                prompt();
                line = readline(&num);
                // call the token function
                // to be able to execute a command with full path /bin/ls
                printf("chars: %s\nnum: %ld\n", line, num);
        }
        free(line);
}

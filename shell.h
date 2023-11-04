#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <errno.h>

int _putchar(char c);
char **tokenize_cmd(char *cmd);
char *readline(size_t *num_chars);
void prompt();
int _strlen(char *str);
void exec(char **cmd);


#endif


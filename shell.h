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

#define LAST_ENTERD 1024

extern char **environ;


int _putchar(char c);
char **tokenize_cmd(char *cmd);
void readline(size_t *num_chars, char *line);
void prompt(void);
int _strlen(char *str);
int exec_cmd(char **cmd, char *cmd_path, char *cmd_copy);
int exit_shs(char *cmd);
char *search_path(char *cmd);
int _strlen(char *str);
int change_dir(char *cmd);
void handle_ctrl_d(void);
void  add_history(char *cmd);


#endif


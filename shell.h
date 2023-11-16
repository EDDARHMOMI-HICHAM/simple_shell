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
#include <ctype.h>

#define LAST_ENTERD 1024

extern char **environ;


int _putchar(char c);
char **tokenize_cmd(char *cmd);
void _readline(char *cmd, int *nread, FILE *file);
void prompt(void);
int _strlen(char *str);
int exec_cmd(char **cmd, char *cmd_path, char *argv[]);
int exit_shs(char *cmd);
char *search_path(char *cmd);
int _strlen(char *str);
int change_dir(char *cmd);
void handle_ctrl_d(void);
void add_history(char *cmd);
void print_env(void);
int check_token(char **tokens, char *argv[]);
void rem_space(char *str);
void free_tokens(char **tokens);

#endif


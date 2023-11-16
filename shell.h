#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

int lsh_ctrld(char **args);
int lsh_cd(char **args);
int lsh_help(char **args);
extern char **environ;
int lsh_exit(char **args);
int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _putchar(char c);


char *_getpath(char **envir);
int _vals_path(char **arg, char **envir);
void _get_env(char **envir);
char **tokenize(char *lineptr);
char *_getline_cmd(void);
void _exit_command(char **args, char *lineptr, int _exit);
int _fork_func(char **arg, char **av, char **envir,
char *lineptr, int np, int c);


#endif

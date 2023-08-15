#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/** FUNCTIONS **/

/* string functions */
int _strlen(const char *str);
void _strcpy(char *dest, const char *src);
int _strcmp(char *s1, char *s2);

/* main.c functions */
void tokenize_input(char *input, char **envp);

/* exec functions */
int execute_command(char **argx, char *lineptr_copy, char* input, char **envp);
char *path_funct(char **envp, char *comm);
int special_commands(char **argx, char *lineptr_copy, char *lineptr, char **envp);

/* 2D pointers functions */
void free_char2D(char **pointer);
char **charray_clone(char **envp);

/* exit functions */
void exit_stat(char **argx, char *lineptr_copy, char *lineptr, int ex_val, char **envp);
int exit_check(char *string_after_exit_command);

/* env function */
void env_fn(char **envp);

#endif

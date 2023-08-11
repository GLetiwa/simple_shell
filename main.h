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
void execute_command(char **argv, char **envp);
char *path_funct(char **envp, char *comm);

/* 2D pointers functions */
void free_char2D(char **pointer, int i);

#endif

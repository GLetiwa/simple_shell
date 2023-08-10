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
void free_char2D(char **pointer, int i);

/* main.c functions */
int main(int ac, char **argv);
void tokenize_input(char *input);
void execute_command(char **argv);


#endif

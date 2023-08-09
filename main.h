#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

/** FUNCTIONS **/
int _strlen(const char *str);
void _strcpy(char *dest, const char *src);
int main(int ac, char **argv);
void tokenize_input(char *input);
void exec(char **argv);

#endif

#ifndef MAIN_H
#define MAIN_H

#define LOGICAL_AND 1
#define LOGICAL_OR 2
#define NO_LOGICAL_OP 0


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

/**
 * struct env_node - double linked list
 * @name: Name of the environment variable
 * @value: Value of the environment variable
 * @next: points to the next environment node
 * Description: double linked list node structure
 */
typedef struct env_node
{
	char *name;
	char *value;
	struct env_node *next;
} env_node;

/** FUNCTIONS **/

/* string functions */
int _strlen(const char *str);
void _strcpy(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);

/* main.c functions */
void tokenize_input(char *input, char **envp, char **argv, int *ex_stat);

/* exec functions */
void execute_command(char **argx, char *argv_0, char *lineptr_copy,
		char *input, char **envp, int *er_val);
char *path_funct(char **envp, char *comm);
int special_commands(char **argx, char *lineptr_copy,
		char *lineptr, char **envp, int *er_val);

/* 2D pointers functions */
void free_char2D(char **pointer);
char **charray_clone(char **envp);
char *env_str(char *dir, int dir_size, char *cur_wd);

/* exit functions */
void exit_stat(char **argx, char *lineptr_copy, char *lineptr,
		int ex_val, char **envp);
int exit_check(char *string_after_exit_command);

/* env function */
int env_fn(char **envp);
extern char **environ;
int ch_wd(char *p_name, char **envp);
int get_env(char **envp, char *env_var);
int _setenv(env_node **head_ptr, char *name, char *value);
int _unsetenv(env_node **head_ptr, char *name);

/* comment handler */
void comment_handler(char *str_add);
char **get_right_command(char **argx, int logical_op __attribute__((unused)));
char **get_left_command(char **argx, int logical_op __attribute__((unused)));
int check_logical_op(char **argx);
void exec_log_op(char **argx, char *argv_0,
	char *lineptr_copy, char *input, char **envp, int *er_val);

#endif

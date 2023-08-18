#include "main.h"

int ch_wd(char *p_name, char **envp);

/**
 * execute_command - executes command in separate process
 * @argx: 2D string containing string + parameters
 * @envp: environment variables
 * @lineptr_copy: copy of the input command line
 * @input: original input command line
 * Return: error value or exit status of the command
 */
int execute_command(char **argx, char *lineptr_copy, char *input, char **envp)
{
	int id = 0, error_val = 0, check = 0;
	char *path_ptr;

	check = special_commands(argx, lineptr_copy, input, envp);
	if (!check)
	{
		if (access(argx[0], F_OK) && argx[0])
		{
			path_ptr = path_funct(envp, argx[0]);
			if (path_ptr)
			{
				free(argx[0]);
				argx[0] = path_ptr;
				id = fork();
			}
		}
		else if (argx[0])
			id = fork();
		if (!id)
		{
			execve(argx[0], argx, envp);
			perror("Error");
			error_val = 127;
		}
		else
		{
			wait(NULL);
			/* printf("worked\n"); */
			error_val = 0;
		}
	}
	return (error_val);
}
/**
 * path_funct - attaches PATH to existing executables
 * @envp: environment variables
 * @comm: executable with potential path
 * Return: NULL or executable + PATH
 */
char *path_funct(char **envp, char *comm)
{
	int i, len = _strlen(comm), str_tok, ret = -1;
	char *token, *str_cp, *comms, *tmp;

	comms = malloc(sizeof(char) * len + 2);
	len = len + 2;
	comms[0] = '/';
	_strcpy(&comms[1], comm);
	for (i = 0; envp[i]; i++)
	{
		tmp = malloc(sizeof(char) * (_strlen(envp[i]) + 1));
		_strcpy(tmp, envp[i]);
		token = strtok(tmp, "=");
		if (_strcmp(token, "PATH") == 0)
		{
			while (token)
			{
				token = strtok(NULL, ":");
				str_tok = (token ? _strlen(token) : 0);
				str_cp = malloc(sizeof(char) * (str_tok + len) + 1);
				if (!str_cp)
					return (0);
				if (token)
				{
					_strcpy(str_cp, token);
					_strcpy(&str_cp[str_tok], comms);
					ret = access(str_cp, F_OK);
					if (ret == 0)
						break;
				}
				free(str_cp);
			}
			free(comms);
			free(tmp);
			break;
		}
		free(tmp);
	}
	return ((ret ? NULL : str_cp));
}
/**
 * special_commands - handles special commands
 * @argx: command and its arguments
 * @lineptr_copy: copy of the input command line
 * @input: original input command line
 * @envp: environment variables
 * Return: 1 if special command is executed, 0 otherwies
 */
int special_commands(char **argx, char *lineptr_copy, char *input, char **envp)
{
	char *comm_and = argx[0], *spec_comm[] = {"exit", "env", "cd",
		"setenv", "unsetenv"};
	env_node *head_ptr = NULL;
	int ex_val = 0, i;

	for (i = 0; i < 5; i++)
		if (!_strcmp(comm_and, spec_comm[i]))
			break;
	if (i > 2)
		return (0);
	switch (i)
	{
		case 0:
			if (argx[1])
				ex_val = (exit_check(argx[1]));
			exit_stat(argx, lineptr_copy, input, ex_val, envp);
			return (1);
		case 1:
			env_fn(envp);
			return (1);
		case 2:
			ch_wd(argx[1], envp);
			return (1);

		case 3:
			if (argx[1] && argx[2])
				_setenv(&head_ptr, argx[1], argx[2]);
			return (1);
		case 4:
			if (argx[1])
				_unsetenv(&head_ptr, argx[1]);
			return (1);
		default:
			break;
	}
	return (0);



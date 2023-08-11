#include "main.h"
/**
 * execute_command - executes command in separate process
 * @argx: 2D string containing string + parameters
 * @envp: environment variables
 */
void execute_command(char **argx, char **envp)
{
	int id = 0;
	char *path_ptr;

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
		execve(argx[0], argx, NULL);
		perror("Error");
	}
	else
	{
		wait(NULL);
		printf("worked\n");
	}
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
			if (ret)
				free(str_cp);
			free(comms);
			free(tmp);
			break;
		}
		free(tmp);
	}
	return ((ret ? NULL : str_cp));
}

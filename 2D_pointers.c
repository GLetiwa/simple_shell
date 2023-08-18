#include "main.h"
#include <limits.h>

/**
 * free_char2D - frees 2D pointer
 * @pointer: 2D pinter to be freed
 */
void free_char2D(char **pointer)
{
	int j;

	for (j = 0; pointer[j]; j++)
		free(pointer[j]);
	free(pointer);
}
/**
 * charray_clone - clones an array of strings
 * @envp: original array of strings
 * Return: cloned array of strings
 */
char **charray_clone(char **envp)
{
	int i = 0, j = 0;
	char **n_envp = NULL;

	while (envp[i])
		i++;
	n_envp = malloc(sizeof(char *) * (i + 2));
	if (!n_envp)
		return (NULL);
	for (j = 0; envp[j]; j++)
	{
		n_envp[j] = malloc(sizeof(char) * (_strlen(envp[j]) + 1));
		if (!n_envp[j])
		{
			for (; j >= 0; j--)
				free(n_envp[j]);
			free(n_envp);
			return (NULL);
		}
		if (envp[j] != NULL)
			_strcpy(n_envp[j], envp[j]);
	}
	return (n_envp);
}
/**
 * env_str - creates an environmental string
 * @dir: directory string
 * @dir_size: size of the directory string
 * @cur_wd: current working directory
 * Return: the environment string
 */
char *env_str(char *dir, int dir_size, char *cur_wd)
{
	char *r_path = NULL, *r_env = NULL;
	int i, j, len = 0;


	r_path = (cur_wd == NULL ? getcwd(NULL, PATH_MAX) : &cur_wd[4]);

	if (r_path != NULL)
	{
		len = _strlen(r_path);
		r_env = malloc(sizeof(char) * (len + dir_size + 1));
		if (!r_env)
			return (NULL);
		for (i = 0, j = 0; i < (len + dir_size); i++)
		{
			if (i < dir_size)
				r_env[i] = dir[i];
			else
			{
				r_env[i] = r_path[j];
				j++;
			}
		}
		r_env[i] = '\0';
		free((cur_wd == NULL ? r_path : cur_wd));
	}
	return ((r_path == NULL ? NULL : r_env));
}

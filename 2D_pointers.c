#include "main.h"

/**
 * free_char2D - frees 2D pointers
 * @pointer: 2D pointer to be freed
 */
void free_char2D(char **pointer)
{
	int j;

	for (j = 0; pointer[j]; j++)
		free(pointer[j]);
	free(pointer);
}
/**
 *
 */
char **charray_clone(char **envp)
{
	int i = 0, j = 0;
	char **n_envp = NULL;

	while (envp[i])
		i++;
	n_envp = malloc(sizeof(char *) * (i + 2));
	if (!n_envp)
		return NULL;
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

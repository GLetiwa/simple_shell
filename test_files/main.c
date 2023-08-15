#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void _strcpy(char *dest, const char *src);
char **charray_clone(char **envp);
int _strlen(const char *str);
void free_char2D(char **pointer);
/**
 *
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
int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}
/**
 *
 */
void _strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
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
/**
 *
 */
int main(void)
{
	extern char **environ;
       	char **env_cp;

	env_cp = charray_clone(environ);
	for (int i = 0; env_cp[i]; i++)
		printf("%s, Number :%d\n", env_cp[i], i);
	free_char2D(env_cp);
	return 0;
}

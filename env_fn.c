#include "main.h"
/**
 * env_fn - 
 * @envp: 
 */
void env_fn(char **envp)
{
	int i;

	for (i = 0; envp[i]; i++)
	{
		write(1, envp[i], _strlen(envp[i]));
		write(1, "\n", 1);
	}
}

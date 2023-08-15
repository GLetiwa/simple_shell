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
/*
int ch_wd(char **argx, char **envp)
{
	char *_path, *old_path, *tmp_path;


} */

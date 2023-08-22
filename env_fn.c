#include "main.h"

int get_env(char **envp, char *env_var);
char *env_str(char *dir, int dir_size, char *cur_wd);
int ch_wd(char *p_name, char **envp);

/**
 * env_fn - displays environment variables
 * @envp: array of environment variables
 */
int env_fn(char **envp)
{
	int i;

	if (envp)
		for (i = 0; envp[i]; i++)
		{
			write(1, envp[i], _strlen(envp[i]));
			write(1, "\n", 1);
		}

	return ((envp ? 0 : 1));
}
/**
 * ch_wd - changes the working directory
 * @p_name: target directory name
 * @envp: array of environment variables
 * Return: Always 0 (Success)
 */
int ch_wd(char *p_name, char **envp)
{
	char *old_wd;
	char *options[] = {NULL, "~", "-"};
	int c_wd, o_wd, h_d, i, res;

	c_wd = get_env(envp, "PWD=");
	o_wd = get_env(envp, "OLDPWD=");
	h_d = get_env(envp, "HOME=");
	for (i = 0; o_wd < 0; i++)
		o_wd = i;
	old_wd = envp[o_wd];
	if (p_name != NULL)
		for (i = 1; i < 3; i++)
			if (!_strcmp(options[i], p_name))
				break;
	switch (i)
	{
		case 0:case 1:	/* cd home */
			res = chdir(&(envp[h_d][5]));
			break;
		case 2: /* cd - */
			res = chdir(&(envp[o_wd][7]));
			break;
		case 3: /* cd path */
			res = chdir(p_name);
			break;
	}
	if (res == -1)
		perror("Not able to cause");
	else
	{
		envp[o_wd] = env_str("OLDPWD=", 7, envp[c_wd]);
		free(old_wd);
		envp[c_wd] = env_str("PWD=", 4, NULL);
	}
	return ((res == -1 ? 1 : 0));

}
/**
 * get_env - Retrieves the index of an environment variable
 * @envp: array of environment variables
 * @env_var: target environment variable
 * Return: index of the target variable, or 1 if not found
 */
int get_env(char **envp, char *env_var)
{
	int i, j;

	if (!envp)
		return (-1);
	for (i = 0; envp[i]; i++)
	{
		for (j = 0; env_var[j]; j++)
		if (!envp[i][j] || (env_var[j] != envp[i][j]))
		{
			j = 0;
			break;
		}
		if (j)
			return (i);
	}
	if (!envp[i])
		return (-1);
	return (-1);
}

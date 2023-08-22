#include "main.h"
/**
 * exit_check - checks if the argument is a valid exit value
 * @argx: argument to check
 * Return: valid exit value or -10000 for error
 */
int exit_check(char *argx)
{
	int i, val, pv, digit;

	val = 0;
	i = (argx[0] == '-' ? 1 : 0);
	for (pv = 10; argx && argx[i] != '\0'; i++)
	{
		if ((argx[i] < '0' || argx[i] > '9'))
		{
			if (!i)
				return (-10000);
			/*
			 * else
			 * break;
			 */
		}
		val *= pv; /* multiply val by the power of 10 */
		digit = argx[i] - '0'; /* convert char into a digit */
		val += digit;

	}

	while (val > 255)
		val = val - 256;
	if (argx[0] == '-')
		val = 256 - val;
	return (val);

}
/**
 * exit_stat - exits shell with a specified exit value
 * @argx: command and its args
 * @lineptr_copy: copy of the input command line
 * @lineptr: original input command
 * @ex_val: exit value to use
 * @envp:environment variables
 */
void exit_stat(char **argx, char *lineptr_copy,
		char *lineptr, int ex_val, char **envp)
{
	if (ex_val == -10000)
	{
		ex_val = 2;
		write(2, argx[0], _strlen(argx[0]));
		write(2, ": ", 2);
		write(2, argx[1], _strlen(argx[1]));
		write(2, " : numeric argument required\n", 29);
	}
	free_char2D(envp);
	free_char2D(argx);
	free(lineptr_copy);
	free(lineptr);
	exit(ex_val);
}

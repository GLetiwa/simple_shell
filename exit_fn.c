#include "main.h"
/**
 *
 */
int exit_check(char *argx)
{
	int i, val, pv, digit;
	pv = val = i = 0;
	if (argx[i] == '-')
		i++;
	for (pv = 1; argx && argx[i] != '\0'; i++)
	{
		if ((argx[i] < '0' || argx[i] > '9'))
		{
			if (!i)
				return(-10000);
			else
				break;
		}
		val *= pv; 
		digit = argx[i] - '0';
		val += digit;

		pv *= 10;
	}
	if (val > 255)
		val = val % 256;
	return (val);

}
/*
 *
 */
void exit_stat(char **argx, int i, char *lineptr_copy, char *lineptr, int ex_val)
{
	if (ex_val == -10000)
	{
		ex_val = 2;
		write(2, argx[0], _strlen(argx[0]));
		write(2, ": ", 2);
		write(2, argx[1], _strlen(argx[1]));
		write(2, " : numeric argument required\n", 29);
	}
	free_char2D(argx, i);
	free(lineptr_copy);
	free(lineptr);
	exit(ex_val);
}

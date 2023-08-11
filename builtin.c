#include "main.h"

int _builtincmd(char **argx)
{
	if (strcmp(argx[0], "exit") == 0)
	{
		printf("Exiting shell....\n");
		exit(0);
	}
	else if (strcmp(argx[0], "cd") == 0)
	{
		if (argx[1] == NULL)
		{
			chdir(getenv("HOME"));
		}
		else
		{
			chdir(argx[1]);
		}
		return (0);
	}

	return (-1);
}
	/* implementation in main */
	/* if (_builtincmd(argx) != 0)
		continue; */

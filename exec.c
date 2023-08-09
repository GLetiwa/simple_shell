#include "main.h"
#include <unistd.h>
#include <stdio.h>

void exec(char **argv)
{
	char *cmd = NULL;
	
	if (argv)
	{
		/* getting command */
		cmd = argv[0];
		if (execve(cmd, argv, NULL) == -1)
		{
			perror("Error:");
		};
	}
}

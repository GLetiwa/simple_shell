#include "main.h"

void execute_command(char **argx)
{
        int id;

        id = fork();
        if (!id)
        {
                if (execve(argx[0], argx, NULL) == -1)
                        perror("Error");
                        
        }
        else
        {
                wait(NULL);
                printf("worked\n");
        }
        return;
}

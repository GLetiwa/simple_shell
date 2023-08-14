#include "main.h"

/**
 * free_char2D - frees 2D pointers
 * @pointer: 2D pointer to be freed
 * @i: number of pointers inside to be freed
 */
void free_char2D(char **pointer, int i)
{
	int j;

	for (j = 0; j < i; j++)
		free(pointer[j]);
	free(pointer);
}


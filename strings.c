#include "main.h"
/**
 * _strlen - checks the length of a string
 * @str: string
 * Return: returns the string length
 */
int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}
/**
 * _strcpy - copies string to the output buffer
 * @src: string to copy
 * @dest: string destination
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
/*
char *_strtok(char *str, char *delimiter)
{
	static char *t_start = NULL;
	static char *t_end = NULL;
	char *rtn;
	size_t *d_len;

	if (str)
	{
		t_start = t_end = str;


	}

	else if (!str && t_end)
	{
		free(t_start);
		d_len = delimited_str(t_end, delimiter);
		t_end = &t_start[d_len[1]];
		t_start[d_len[0]] = '\0';
	}
	else
		return (NULL);
	return (t_start);
}
size_t *delimited_str(static char token, char *d)
{
	size_t i, j, k, count, values[2];


	for (i = 0; token[i]; i++)
	{
		for (j = 0, k = i, count = 0;(token[i] == d[0]) && d[j]; k++, j++)
		{
			if (token[k] == d[i])
				count++;

			else
			{
				count = 0;
				break;
			}
		}
		if (count != 0)
		{
			values[0] = i;
			values[1] = i + (_strlen(d) - 1);
		}
	}
}
*/

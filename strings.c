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

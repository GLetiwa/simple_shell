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
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: returns the difference
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while ((s1[i] != '\0') && (s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}


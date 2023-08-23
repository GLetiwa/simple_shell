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
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strdup - duplicates a string
 * @str: string to be duplicated
 *
 * Return: duplicated string
 */
char *_strdup(char *str)
{
	size_t len = 0;
	char *duplicate = NULL;

	if (!str)
		return (NULL);
	len = _strlen(str) + 1;
	duplicate = (char *)malloc(len);

	if (duplicate)
		_strcpy(duplicate, str);
	return (duplicate);
}


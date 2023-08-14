#include <stdlib.h>
#include <stdio.h>
#include<stddef.h>

/**
 * is_delim - checks if a character is a delimeter
 * @character: current character in check
 * @delimeter: the delimiter to be checked
 *
 * Return 1 if character is delimiter and 0 if not
 */
char is_delim(char character, char *delimiter)
{
	int i;

	for (i = 0; delimiter[i] != '\0'; i++)
	{
		if (character == delimiter[i])
		{
			return (1);
		}
	}
	return (0);
}

/**
 * next_delim - checks for the next delimiter
 * @str: the string in check
 * @delim: delimiter to be checked
 *
 * Return: position of the delimiter
 */
int next_delim(char *str, char *delim)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (is_delim(str[i], delim))
			return (i);
		else if (str[i + 1] == '\0')
			return (i + 1);
	}
	return (0);
}
/**
 * _strtok - tokenizes input string
 * @str: input string
 * @delim: delimiter in check
 *
 * Return: generated tokens
 */
char *_strtok(char *str, char *delim)
{
	static char *str_cpy;
	char *buffer;
	static int position;
	int i, prev_position; /* remember starting position of token */

	if ((!str && !str_cpy))
	{
		return (NULL);
	}
	else if (!str)
	{
		if (str_cpy[position - 1] == '\0')
			return (NULL);
		/* update to point to the remaining parts of the string */
		str = str_cpy + position;
	}
	else
	{
		str_cpy = str; /* if it is a new str to be tokenized */
		position = 0;
	}
	for (; is_delim(*str, delim); str++, position++)
	;
	prev_position = position;
	position += next_delim((str), delim);
	/* buffer to hold extracted tokens */
	buffer = malloc(sizeof(char) * (position - prev_position + 1));
	for (i = 0; i < (position - prev_position); i++)
		buffer[i] = str[i];
	buffer[i] = '\0';
	position++;
	return (buffer);

}

int main(void)
{
	char *str = "Grace and Anthony's project";
	char *token = NULL;
	char *del = " ";
	
	token = _strtok(str, del);
	while (token != NULL)
	{
		printf("token %s\n", token);
		token = _strtok(NULL, del);
	}
	return (0);
}


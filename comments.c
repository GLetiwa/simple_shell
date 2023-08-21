#include "main.h"
/**
 * comment_handler - replaces comments with a null terminator
 * @str_add: address of the string to be handled
 *
 * Return: Always 0 (Success)
 */
void comment_handler(char *str_add)
{
	int i;

	for (i = 0; str_add[i] != '\0'; i++)
	{
		if (str_add[i] == '#' && (i == 0 || str_add[i - 1] == ' '))
		{
			str_add[i] = '\0';
			break;
		}
	}
}

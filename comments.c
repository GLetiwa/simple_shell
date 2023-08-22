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
/**
 * check_logical_op - checks for a logical operator
 * @argx: arguments passed
 *
 * Return: logical operator found
 */
int check_logical_op(char **argx)
{
	int i = 0;

	while (argx[i])
	{
		if (_strcmp(argx[i], "&&") == 0)
		{
			return (LOGICAL_AND);
		}
		else if (_strcmp(argx[i], "||") == 0)
		{
			return (LOGICAL_OR);
		}
		i++;
	}
	return (NO_LOGICAL_OP);
}
/**
 * get_left_command - gets the command at the left side of log op
 * @argx: arguments passed
 * @logical_op: logical operator in place
 *
 * Return: command at the left side of the logical op
 */
char **get_left_command(char **argx, int logical_op)
{
	int i = 0, count = 0;
	char **left_cmd = NULL;

	while (argx[i] && i < logical_op)
	{
		count++;
		i++;
	}
	left_cmd = malloc((count + 1) * sizeof(char *));
	if (!left_cmd)
	{
		perror("Memory allocation error");
		return (NULL);
	}
	for (i = 0; i < count; i++)
	{
		left_cmd[i] = strdup(argx[i]);
	}
	left_cmd[count] = NULL;
	return (left_cmd);
}
/**
 * get_right_command -gets the command at the right side of log op
 * @argx: arguments passed
 * @logical_op: logical operator in place
 *
 * Return: command at the right side of the logical operator
 */
char **get_right_command(char **argx, int logical_op)
{
	int i = logical_op + 1, count = 0;
	char **right_cmd = NULL;

	while (argx[i] && argx[i + count])
	{
		count++;
	}
	right_cmd = malloc((count + 1) * sizeof(char *));
	if (!right_cmd)
	{
		perror("Memory allocation error");
		return (NULL);
	}
	for (i = logical_op + 1; i < logical_op + count; i++)
	{
		right_cmd[i - (logical_op + 1)] = strdup(argx[i]);
	}
	right_cmd[count] = NULL;
	return (right_cmd);
}

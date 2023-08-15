#include "main.h"

int _setenv(env_node **head_ptr, char *name, char *value)
{
	env_node *head = *head_ptr;
	env_node *ptr = head;
	env_node *new;

	while (ptr != NULL)
	{
		if (_strcmp(ptr->name, name) == 0)
		{
			free(ptr->value);
			ptr->value = _strdup(value);
			if (ptr->value == NULL)
			{
				perror("Memory allocation error");
				return (1);
			}
			return (0);
		}
		ptr = ptr->next;
	}
	new = (env_node *)malloc(sizeof(env_node));
	if (new == NULL)
	{
		perror("Memory allocation error");
		return (1);
	}
	new->name = _strdup(name);
	new->value = _strdup(value);
	if (new->name == NULL || new->value == NULL)
	{
		perror("Memory allocation error");
		free(new->name);
		free(new->value);
		free(new);
		return (1);
	}
	new->next = head;
	*head_ptr = new;
	return (0);
}

int _unsetenv(env_node **head_ptr, char *name)
{
	env_node *head = *head_ptr;
	env_node *ptr = head;
	env_node *prev = NULL;

	while (ptr != NULL)
	{
		if (_strcmp(ptr->name, name) == 0)
		{
			if (prev == NULL)
			{
				*head_ptr = ptr->next;
			}
			else
			{
				prev->next = ptr->next;
			}
			free(ptr->name);
			free(ptr->value);
			free(ptr);
			return (0);
		}
		prev = ptr;
		ptr = ptr->next;
	}
	perror("Environment variable not found");
	return (1);
}
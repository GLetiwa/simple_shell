#include "main.h"
/**
* int main -
* @ac: 
*@argv:
*Return: 0 Always (Success)
*/
int main(int ac, char **argv)
{
	char *prompt = "(Eshell) $ ", *lineptr;
	size_t n = 0; 
	ssize_t chars_read;

	(void)ac; (void)argv;
	while (1)
	{
		printf("%s", prompt);
		chars_read = getline(&lineptr, &n, stdin);
		if (chars_read == -1)
		{
			printf("Exiting shell....\n");
			free(lineptr);
			return (-1);
		}
		printf("%s\n", lineptr);
		tokenize_input(lineptr);
		free(lineptr);
		lineptr = NULL;
	}
	return (0);
}
void tokenize_input(char *input)
{
	char *delim = " \n", *token, *lineptr_copy;
	int i, string_tokens = 0;
	char **argx;
	size_t chars_read = _strlen(input);
	
	lineptr_copy = malloc(sizeof(char) * chars_read);
	if (!lineptr_copy)
	{
		perror("Memory allocation error");
		return;
	}
	_strcpy(lineptr_copy, input);
	token = strtok(input, delim);
	while (1)
	{
		string_tokens++;
		if (token)
			token = strtok(NULL, delim);
		else
			break;
	}
	string_tokens++;
	argx = malloc(sizeof(char *) * string_tokens);
	token = strtok(lineptr_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argx[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy(argx[i], token);
		token = strtok(NULL, delim);
		printf("%s\n", argx[i]);
	}
	free_char2D(argx, i);
	/*argx[i] = NULL; */
	free(lineptr_copy);
}

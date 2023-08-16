#include "main.h"

/**
* main - executes program
* Return: 0 Always (Success)
*/
int main(void)
{
	char *prompt = "(Eshell) $ ", *lineptr, **envp;
	size_t n = 0;
	ssize_t chars_read;
	extern char **environ;

	envp = charray_clone(environ);
	while (1)
	{
		printf("%s", prompt);
		chars_read = getline(&lineptr, &n, stdin);
		if (chars_read == -1)
		{
			printf("Exiting shell....\n");
			free(lineptr);
			/* free_char2D(environ);*/
			free_char2D(envp);
			return (-1);
		}
	/*	printf("%s\n", lineptr);*/
		tokenize_input(lineptr, envp);
		free(lineptr);
		lineptr = NULL;
	}

	return (0);
}
/**
 * tokenize_input - obtains tokens from strings
 * @input: string input from getline
 * @envp: 2D string from main args
 */
void tokenize_input(char *input, char **envp)
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
	argx = malloc(sizeof(char *) * string_tokens + 1);
	token = strtok(lineptr_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argx[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy(argx[i], token);
		token = strtok(NULL, delim);
	/*	printf("%s\n", argx[i]); */
	}
	argx[i] = NULL;
	if (argx[0])
		execute_command(argx, lineptr_copy, input, envp);
	free_char2D(argx);
	free(lineptr_copy);
}

#include "main.h"

/**
* main - executes program
* @argc: argument count
* @argv: arguments passed to main
* @envp_1: environment variables
* Return: 0 Always (Success)
*/
int main(int argc __attribute__((unused)),
		char **argv __attribute__((unused)), char **envp_1)
{
	char *prompt = "(Eshell) $ ", *lineptr, **envp;
	size_t n = 0, len = _strlen(prompt);
	ssize_t chars_read;

	envp = charray_clone(envp_1);
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, prompt, len);
		}
		chars_read = getline(&lineptr, &n, stdin);
		if (chars_read == -1)
		{
			/* write(STDOUT_FILENO, "Exiting shell....\n", 18); */
			free(lineptr);
			/* free_char2D(environ);*/
			free_char2D(envp);
			return (-1);
		}
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
	}
	argx[i] = NULL;
	if (argx[0])
		execute_command(argx, lineptr_copy, input, envp);
	free_char2D(argx);
	free(lineptr_copy);
}

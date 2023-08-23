#include "main.h"

/**
* main - executes program
* @argc: argument count
* @argv: arguments passed to main
* @envp_1: environment variables
* Return: 0 Always (Success)
*/
int main(int argc __attribute__((unused)),
		char **argv, char **envp_1 __attribute__((unused)))
{
	char *prompt = "($) ", *lineptr = NULL, **envp = NULL;
	size_t n = 0, len = _strlen(prompt);
	ssize_t chars_read = 0;
	int exit_stat = 0;

	envp = charray_clone(environ); /* (envp_1);*/
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, prompt, len);
		chars_read = getline(&lineptr, &n, stdin);
		if (chars_read == -1)
		{
			free(lineptr);
			free_char2D(envp);
			if (isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "\n", 1);
			if (exit_stat > 255)
				return (exit_stat / 256);
			return (exit_stat);
		}
		/* comment_handler(lineptr); */
		tokenize_input(lineptr, envp, argv, &exit_stat);
		free(lineptr);
		lineptr = NULL;
	}
	return (0);
}
/**
 * tokenize_input - obtains tokens from strings
 * @input: string input from getline
 * @envp: 2D string from main args
 * @argv: arguments passed
 * @ex_stat: command exit status
 */
void tokenize_input(char *input, char **envp, char **argv, int *ex_stat)
{
	char *delim = " \n", *token = NULL, *lineptr_copy = NULL;
	int i = 0, string_tokens = 0;
	char **argx = NULL;
	size_t chars_read = _strlen(input);

	lineptr_copy = malloc(sizeof(char *) * chars_read);
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
	argx = malloc(sizeof(char *) * (string_tokens + 1));
	token = strtok(lineptr_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		argx[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy(argx[i], token);
		token = strtok(NULL, delim);
	}
	argx[i] = NULL;
	for (i = 0; argx[i] != NULL; i++)
	{
		if (strcmp(argx[i], "&&") == 0 || strcmp(argx[i], "||") == 0)
			argx[i] = NULL;
	}
	if (argx[0])
		execute_command(argx, argv[0], lineptr_copy, input, envp, ex_stat);
	free_char2D(argx);
	free(lineptr_copy);
}

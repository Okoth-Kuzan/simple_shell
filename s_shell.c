#include "main.h"

/**
 * main - entry point for the shell program
 *
 * Return: exit status of the shell program.
 */

int main(void)
{
	char *path_env = getenv("PATH");
	char *token = NULL;
	char input[MAX_INPUT_SIZE];
	char *args[MAX_INPUT_SIZE / 2 + 1];
	int i = 0;
	int should_run = 1;

	fprintf(stderr, "PATH: %s\n", path_env);

	while (should_run)
	{
		write(STDOUT_FILENO, "Shell> ", 7);

		if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
		{
			write(STDOUT_FILENO, "\nExiting the shell.\n", 20);
			break;
		}
		input[strcspn(input, "\n")] = 0;

		for (token = strtok(input, " "); token != NULL; token = strtok(NULL, " "))
		{
			args[i++] = token;
		}
		args[i] = NULL;

		if (args[0] != NULL)
		{
			fprintf(stderr, "Executing command: %s\n", args[0]);

			execute_command(args);
		}
	}

	return (0);
}

#include "main.h"

/**
 * main - entry point for the shell program
 *
 * Return: exit status of the shell program.
 */

int main(void)
{
	char *token = NULL;
	char input[MAX_INPUT_SIZE];
	char *args[MAX_INPUT_SIZE / 2 + 1];
	int i = 0;
	int should_run = 1;

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

		execute_command(args);
	}

	return (0);
}


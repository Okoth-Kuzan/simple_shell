#include "main.h"

/**
 * main - entry point for the shell program
 *
 * Return: exit status of the shell program.
 */

int main(void)
{
	int i = 0;
	char input[MAX_INPUT_SIZE];
	char *token = strtok(input, " ");
	char *args[MAX_INPUT_SIZE / 2 + 1];
	int should_run = 1;
	pid_t pid = fork();

	while (should_run)
	{
		write(STDOUT_FILENO, "($) ", 4);

		if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
		{
			write(STDOUT_FILENO, "\nExiting the shell.\n", 20);
			break;
		}

		input[strcspn(input, "\n")] = 0;

		if (strcmp(input, "exit") == 0)
		{
			write(STDOUT_FILENO, "Exiting the shell.\n", 19);
			break;
		}
		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		if (pid < 0)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			char *command_path = find_command_path(args[0]);

			if (command_path == NULL)
			{
				fprintf(stderr, "Command not found: %s\n", args[0]);
				exit(EXIT_FAILURE);
			}
			if (execve(command_path, args, environ) == -1)
			{
				perror("execve failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;

			waitpid(pid, &status, 0);
		}
	}
	return (0);
}

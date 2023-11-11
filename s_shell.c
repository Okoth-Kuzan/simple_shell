#include "shell.h"
#include <stdio.h>

/**
 * compare_entries - Modifies a pointer.
 *
 * @a: retrieves file a
 * @b: retrieves file b
 *
 * Return: Always 0.
 */

int compare_entries(const struct dirent **a, const struct dirent **b)
{
	int cmp = strcasecmp((*a)->d_name, (*b)->d_name);

	if (cmp != 0)
	{
		return (cmp);
	}
	else
	{
		return (strcmp((*a)->d_name, (*b)->d_name));
	}
}

void execute_command(char *command, char *args[]);

/**
 * main - checks the code
 *
 *
 * Return: Always 0.
 */

int main(void)
{
	char input[MAX_COMMAND_LENGTH];

	while (1)
	{
		write(STDOUT_FILENO, "simple_shell$ ", 14);
		if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			if (feof(stdin))
			{
				write(STDOUT_FILENO, "\n", 1);
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("fgets");
				exit(EXIT_FAILURE);
			}
		}
		if (input[strlen(input) - 1] == '\n')
		{
			input[strlen(input) - 1] = '\0';
		}
		if (strcmp(input, "exit") == 0)
		{
			exit(EXIT_SUCCESS);
		}
		else if (strncmp(input, "cd", 2) == 0)
		{
			char *arg = input + 3;

			if (chdir(arg) != 0)
			{
				perror("chdir");
			}
		}
		else
		{
			char *token = strtok(input, " ");
			char *command = token;
			char *args[MAX_ARGS];

			int arg_count = 0;

			while (token != NULL && arg_count < MAX_ARGS - 1)
			{
				token = strtok(NULL, " ");

				if (token != NULL)
				{
					args[arg_count] = token;
					arg_count++;
				}
			}
			args[arg_count] = NULL;

			execute_command(command, args);
		}
	}
	return (0);
}

/**
 * execute_command : Exectues a command and arg
 *
 * @command: writes defined fucntion
 *
 * @args: returns arg
 * Return 1
 *
 */

void execute_command(char *command, char *args[])
{
	pid_t pid;

	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(command, args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
	do {
	waitpid(pid, &status, WUNTRACED);
	}

	while {
	(!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	}
}

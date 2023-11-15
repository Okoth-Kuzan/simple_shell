#include "main.h"

/**
 * execute_command - executes command.
 * args: Command execution failed 
 *
 * Return: 0
 */

void execute_command(char *args[])
{
	char *command_path = find_command_path(args[0]);

	if (command_path != NULL)
	{
		pid_t pid = fork();

		if (pid < 0)
		{
			write(STDERR_FILENO, "Fork failed.\n", 13);
			_exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(command_path, args, environ) == -1)
			{
				write(STDERR_FILENO, "Command execution failed.\n", 26);
				_exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;

			waitpid(pid, &status, 0);

			if (status != 0)
			{
				write(STDERR_FILENO, "Command execution failed.\n", 26);
			}
		}
		free(command_path);
	}
	else
	{
		write(STDERR_FILENO, "Command not found.\n", 19);
	}
}


#include "main.h"

/**
 * execute_command - executes a command in a new process.
 *
 * @args: array of strings representing the command and its arguments.
 */
void execute_command(char *args[])
{
	char *command_path = find_command_path(args[0]);

	if (command_path != NULL)
	{
		pid_t pid = fork();

		if (pid < 0)
		{
			perror("Fork failed");
			_exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(command_path, args, environ) == -1)
			{
				perror("execve");
				_exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;

			waitpid(pid, &status, 0);

			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			{
				fprintf(stderr, "Command execution failed with status: %d\n",
						WEXITSTATUS(status));
			}
		}
		free(command_path);
	}
	else
	{
		fprintf(stderr, "Command not found: %s\n", args[0]);
	}
}


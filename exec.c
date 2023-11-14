#include "main.h"

void execute_command(char *command, char *environ[])
{
	pid_t pid = fork();
	char *args[2];

	if (pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		_printstring("Child process executing: ");
		_printstring(command);
		_putchar('\n');

		 args[0] = command;
		 args[1] = NULL;

		 if (execve(command, args, environ) == -1)
		 {
			 perror("Error executing command");
			 exit(EXIT_FAILURE);
		 }
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			_printstring("Child process exited with status: ");
			printf("%d\n", WEXITSTATUS(status));
		}
		else if (WIFSIGNALED(status))
		{
			_printstring("Child process terminated by signal: ");
			printf("%d\n", WTERMSIG(status));
		}
	}
}


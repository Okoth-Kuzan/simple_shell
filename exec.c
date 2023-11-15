#include "main.h"

char *find_command_path(const char *command)
{
	char *path_env = getenv("PATH");
	char *path_copy = strdup(path_env);
	char *token = strtok(path_copy, ":");
	char *full_path = NULL;

	if (path_env == NULL)
	{
		write(STDERR_FILENO, "PATH environment variable not set.\n", 36);
		exit(EXIT_FAILURE);
	}

	if (path_copy == NULL)
	{
		write(STDERR_FILENO, "Memory allocation failed.\n", 26);
		exit(EXIT_FAILURE);
	}

	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			write(STDERR_FILENO, "Memory allocation failed.\n", 26);
			exit(EXIT_FAILURE);
		}
		sprintf(full_path, "%s/%s", token, command);

		if (access(full_path, F_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);

	return (NULL);
}


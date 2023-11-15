#include "main.h"

/**
 * find_command_path - find the full path of an executable command
 *
 * @command: the command
 * Return: full path of the command if found, or NULL if not found
 */
char *find_command_path(const char *command)
{
	char *path_env = getenv("PATH");
	char *path_copy = strdup(path_env);
	char *token = strtok(path_copy, ":");
	char *full_path = NULL;

	if (path_env == NULL)
	{
		perror("PATH environment variable not set");
		return (NULL);
	}

	if (path_copy == NULL)
	{
		perror("Memory allocation failed");
		return (NULL);
	}

	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);

		if (full_path == NULL)
		{
			perror("Memory allocation failed");
			free(path_copy);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", token, command);

		if (access(full_path, X_OK) == 0)
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


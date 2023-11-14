#include "main.h"

int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t read_result;

	while (1)
	{
		_printstring("simple_shell> ");

		read_result = getline(&input, &input_size, stdin);

		if (read_result == -1)
		{
			if (feof(stdin))
			{
				_printstring("\n");
				break;
			}
			else
			{
				perror("Error reading input");
				exit(EXIT_FAILURE);
			}
		}

		input[strcspn(input, "\n")] = 0;

		if (strcmp(input, "exit") == 0)
		{
			free(input);
			break;
		}
		_printstring(" ");
		_printstring(input);
		_putchar('\n');

		free(input);
		input = NULL;
		input_size = 0;

	}
	return (0);
}

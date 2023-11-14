#include "main.h"

/**
 * _putchar - Writes a single character to the standard output.
 *
 * @c: The character to be written.
 * Return: number of characters written (1 if successful, -1 on failure).
 */

int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _printstring - Prints a string to the standard output.
 *
 * @str: pointer to the null-terminated string to be printed.
 * Return: The total number of characters printed.
 */

int _printstring(char *str)
{
	int i = 0, count = 0;

	while (str[i])
	{
		count += _putchar(str[i++]);
	}
	return (count);
}

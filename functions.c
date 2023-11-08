#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 *@c:The character to print
 *
 * Return: on success 1.
 * On error, -1 is returned and erno is set appropriately
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _printstring(char *str)
{
	int i = 0, count = 0;

	while (str[i])
	{
		count += _putchar(str[i++]);
	}
	return (count);
}

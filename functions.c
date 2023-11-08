#include "shell.h"

/**
 * _putchar - writes the character c to stdout 
 * @c: The character to print 
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _printstring(char *str)
{
	int i = 0, count = 0;
	while(str[i])
	{
		count += _putchar(str[i++]);
	}
	return (count);
}

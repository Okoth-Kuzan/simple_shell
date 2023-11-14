#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int _putchar(char c);
int _printstring(char *str);
void execute_command(char *command, char *environ[]);

#endif

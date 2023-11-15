#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_INPUT_SIZE 1024

extern char **environ;

void execute_command(char *args[]);
void execute_builtin(char *args[]);
char *find_command_path(const char *command);
ssize_t custom_getline(char **lineptr, size_t *n);

#endif

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

void execmd(char **argv);
char *get_path(char *cmd);
void built_in_exit(char **argv);
void print_env(char **argv);
int empty_line(char **argv);

extern char **environ;

#endif

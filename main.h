#ifndef main_h
#define main_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

char **creatoken(char *buf);
char *check_access(char *paths[], char *command);
void fork_and_exec(char *command, char **parameters);
char *_getenv(char *name);
char **path_dirs_to_p(void);
void free_p(char **p);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int function (long int a, int *cont);
int _printf(const char *format, ...);

#endif

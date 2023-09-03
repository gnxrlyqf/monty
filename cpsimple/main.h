#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct linked - struct
 * @dir: directory name
 * @next: adress of next dir
 * des: linked struct set to make a list of path directores
 */

typedef struct linked
{
	char *dir;
	struct linked *next;
} linked;

char **splitstr(char *buffer, char *idf);
char *_which(char *filename, char *progname, char **envp);
char *_getenv(const char *name, char **environ);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
linked *pathlist(linked *head, char *path);
ssize_t _getline(char **line, size_t *n, int fd);
int exec(char **cmd, char *progname, char **envp);
void error_non_inter(char *cmdname, char *pgmname);

int _atoi(char *s);
char *_strchr(char *s, char c);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int check(char **cmd, char **env);
void printenv(char **env);
void free_grid(char **grid);
void free_list(linked *head);

#endif

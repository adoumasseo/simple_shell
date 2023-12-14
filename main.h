#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

char *_strcopy(char *str);
char **_strtok(char *str, char *delim);
int _strlen(char *str);
char *_strchrg(char *str, char end);
char *_strchr(char *str, char delim);
int _word_count(char *str, char delim);
void _free_array_i(char **array, int j);
void _free_array(char **array);
void exeve(char **array, char **env, char *argv);
void _strcopy2(char *nstr, char *src, int n);
int _strcmp(char *str1, char *str2);
char *_getenv(char *name, char **env, char **tmp);
char *string_nconcat(char *s1, char *s2);
int _search_file(char *file_name, char **env);
#endif

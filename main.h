#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <limits.h>

int run_cmd(char **cmd);
char *read_cmd(void);
int _putchar(char c);
void print_str(char *str);
unsigned int str_leng(char *str);
char *copy_str(char *str);
char *length_str(char *str);
int comp_str(char *txt1, char *txt2);
char *get_env(char **env, char *pathname);
void *resize_mem(void *p, unsigned int old_taille, unsigned int new_taille);
char **split_txt(char *ligne, char *charactere);
char **get_path(char **env);
char *conca_str(char *str1, char *str2);
char *conca_path(char **str, char **nouveau);

#endif

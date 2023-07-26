#ifndef MAIN_H
#define MAIN_H


#define PROMPT "#my_shell$ "
#define BUFF_SIZE 1024

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

extern char **environ;

/**
 * struct data - holds the main data.
 * @av: Array of arguments to pass for execve.
 * @cmd: The user input, the command line.
 * @programme_name: The name of the shell program.
 * @last_exit_stat: last exit status of last command executed.
 * @free_set_env: 1 if user did exec setenv (use it to free memory).
 */
typedef struct data
{
	char *cmd;
	char **av;
	int free_set_env;
	const char *programme_name;
	int last_exit_stat;
} data;

/**
 * struct integral - holds the data from the main.
 * @cmd: built in cmd
 * @f: function of integral cmd
 */
typedef struct integral
{
	const char *cmd;
	void (*f)(data *d);
} integral;


/* helpers.c */
void _printf(const char *str);
void free_p_array(char **array);
void split_str(data *d, const char *delim);
void data_initiat(data *d, const char *programme_name);
void get_prompt_cmd(data *d);

/* helpers2.c */
void _perror(const char *str1, const char *str2);
void trim_str(char *str);
void *_reallocat(void *ptr, unsigned int new_size);

/* path.c */
char *get_env_var(char *name);
int locate_file_cmd(data *d);
int init_env(data *d, char *name, char *value);

/* integral.c */
int is_builtin_exec(data *d);
void exit_shell(data *d);
void curr_env(data *d);
void set_env(data *d);
void rm_env_var(data *d);
void change_dir(data *d);

/* string_utils.c */
unsigned int str_leng(char *str);
int compare_str(const char *s1, const char *s2);
int cmp_str(const char *s1, const char *s2, int n);
char *copy_str(char *dest, const char *src);
char *append_str(char *dest, const char *src);

/* string_utils2.c */
char *duplicate_str(const char *str);
int is_number(const char *status);
int is_digit(int c);

/* exec.c */
void new_process(data *d);
void sign_handler(int sig);
void exec_cmd(data *d);
ssize_t read_input_file(char **str_ptr, size_t *n, FILE *stream);

#endif


#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define PATH_MAX 4096
#define DELIM " \t\r\n\a"
#define PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))

extern char **environ;

/**
 * struct builtin - contain builtin to handle and function to execute
 * @command:pointer to char
 * @fun:fun to execute when builtin true
 */

typedef struct  builtin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

char *_strtok(char *str, const char *tok);
unsigned int contains_char(char c, const char *str);

int _strlen(const char *s);
int _putchar(char c);
int _atoi(const char *s);

int _strcmp(const char *s1, const char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int num_len(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);

int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(const char *str);


void *fill_an_array(void *a, int num, unsigned int len);
char *_memcpy(char *dest, const char *src, unsigned int n);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);

void prompt(void);
void signal_to_handle(int sig);
char *_getline(void);

int path_cmd(char **line);
char *_getenv(char *name);
char **parse_cmd(char *cmd);
int handle_builtin(char **cmd, int ex_status);
void read_file(char *filename, char **argv);
char *build(char *token, char *value);
int check_builtin(char **cmd);

int check_cmd(char **tokens, char *line, int count, char **argv);
void execute_file(char *line, int counter, FILE *fp, char **argv);
void exit_file(char **cmd, char *line, FILE *fd);

void handle_comments(char *buff);
int history(char *input);
int print_hist(char **cmd, int er);
int print_env(char **cmd, int x);
int change_dir(char **cmd, int er);
int print_help(char **cmd, int er);
int echo_call(char **cmd, int er);
void ex_it(char **cmd, char *input, char **argv, int count);
int print_echo(char **cmd);

void print_pos_number(unsigned int n);
void print_int(int n);
void print_error(char *line, int c, char **argv);
void custom_error(char **argv, int c, char **cmd);

#endif /* MAIN_H */

#ifndef _SHELL_HEADER_H
#define _SHELL_HEADER_H
#define MAX_INPUT_SIZE 1024
#define READ_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int main(void);
char *read_input(void);
void display_error(char *msg);
int execute_input(char **args);
void handle_sigint(int signo);
void handle_sigquit(int signo);
void handle_sigstp(int signo);
void free_tok(char **tokens);
char **parse_input(char *input);
char *_getline(void);
char **parse_input_with_args(char *input);

#endif

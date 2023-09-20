#ifndef _SHELL_HEADER_H
#define _SHELL_HEADER_H
#define MAX_INPUT_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>


int main(void);
void shell_print(const char *letters);
void display_prompt(void);
void execute_input(char *input);
pid_t create_process_id(void);
void handle_execution_error(char *input);
char *read_input(char **input, size_t *input_size);
extern char **environ;
extern bool shell_running;
void signal_handler(int signum);
size_t input_size;
#endif

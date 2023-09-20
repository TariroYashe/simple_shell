#include "shell_header.h"

/**
 * handle_execution_error - Handle errors that occur while executing a command
 * @input: Pointer to a char strng representing the shell command to be exec
 *
 * Description: This func takes the command as an argument and prints an error
 * message using perror before exiting the program with an error code
 */
void handle_execution_error(char *input)
{
perror(input);
_exit(1);
}

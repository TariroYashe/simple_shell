#include "shell_header.h"

/**
* execute_input - func to execute the input
* @input : is a pointer to a char string rep the shell input to be exec
* Description : This function takes a single argument, input, which is
* a pointer to a character string representing the shell input to be executed.
*/
void execute_input(char *input)
{
int outcome;
pid_t process_id = create_process_id();

char **args = malloc(2 * sizeof(char *));
if (args == NULL)
{
perror("malloc");
exit(1);
}

args[0] = input;
args[1] = NULL;

if (process_id == 0)
{
if (execve(input, args, environ) == -1)
{
handle_execution_error(input);
}
}
else
{
if (waitpid(process_id, &outcome, 0) == -1)
{
perror("waitpid");
exit(1);
}
if (outcome == 0)
{
shell_print(" ");
}
else
{
shell_print(" ");
_exit(outcome);
}
}

free(args);
}



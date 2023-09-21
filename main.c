#include "shell_headeri.h"

/**
* main - implements a simple shell
*
* Return: EXIT_SUCCESS.
*/
int main(void)
{
char *input;
char **args;
int status;

/* Register signal handlers */
signal(SIGINT, handle_sigint);
signal(SIGQUIT, handle_sigquit);
signal(SIGTSTP, handle_sigstp);

do {
input = _getline(); /* Use the provided _getline function*/
if (!input) /* NULL input indicates EOF or failure, exit the loop */
break;

args = parse_input(input);
if (!args || !*args)
{
free(input);
free_tok(args);
continue;
}
status = execute_input(args);
free(input);
free_tok(args);

/* Set status to 1 to continue the loop */
status = 1;
} while (status);

return (EXIT_SUCCESS);
}

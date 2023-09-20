#include "shell_header.h"
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
int is_interactive = isatty(STDIN_FILENO);

signal(SIGINT, handle_sigint);
signal(SIGQUIT, SIG_IGN);
signal(SIGTSTP, SIG_IGN);

do {
if (is_interactive)
write(STDOUT_FILENO, "($) ", 4);

input = _getline();
if (!input || !*input) /* EOF detected, exit the loop */
break;

args = parse_input_with_args(input);
if (!args || !*args)
{
free(input);
continue;
}

status = execute_input(args);

free(input);
free_tok(args);
} while (status);

return (EXIT_SUCCESS);
}

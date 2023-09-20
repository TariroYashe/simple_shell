#include "shell_header.h"

/**
* read_input - Read a line of input from the user.
*
* Return: A pointer to the input line, or NULL on failure.
*/
char *read_input(void)
{
char *input = NULL;
size_t bufsize = 0;

if (isatty(STDIN_FILENO)) /*Check if the input is from a terminal*/
write(STDOUT_FILENO, "($) ", 4);/*Display prompt for interactive mode*/

if (getline(&input, &bufsize, stdin) == -1)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
free(input);
return (NULL);
}

return (input);
}

#include "shell_header.h"

bool shell_running = true;
/**
* main - Implements a simple shell
*
* Return: EXIT_SUCCESS.
*/
int main(void)
{
char *input;

signal(SIGINT, SIG_IGN);
signal(SIGQUIT, SIG_IGN);

do {
display_prompt();

input_size = MAX_INPUT_SIZE;
input = read_input(&input, &input_size);


if (!input || !*input)
break;

execute_input(input);
free(input);

} while (1);

return (EXIT_SUCCESS);
}

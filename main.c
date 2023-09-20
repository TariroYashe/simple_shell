#include "shell_header.h"

/**
* main - Entry point for the simple shell program
*
* Description:
* This function serves as the entry point for the simple shell program. It
* displays a prompt, reads user input, executes simple commands, and repeats
* until an EOF condition (Ctrl+D) is encountered.
*
* Return: Always returns 0 to indicate successful execution.
*/
int main(void)
{
char *input = NULL;
size_t input_size = 0;

while (1)
{
display_prompt();
input = read_input(&input, &input_size);

if (input == NULL)
{
break;
}

if (strlen(input) > 0)
{
execute_input(input);
}
}

free(input);

return (0);
}


#include "shell_header.h"

/**
* read_input - Function that reads input from the user
* @input: A pointer to a pointer to char - holds the addr of the inputted str
* @input_size: A pointer to size_t - holds the size of the inputted string
*
* Description: it reads the input from user.
* Return: pointer to the inputted string
*/

char *read_input(char **input, size_t *input_size)
{
ssize_t input_length;

input_length = getline(input, input_size, stdin);

if (input_length == -1)
{
free(*input);
*input = NULL;
}
else
{
if (input_length > 0 && (*input)[input_length - 1] == '\n')
{
(*input)[input_length - 1] = '\0';
}
}

return (*input);
}

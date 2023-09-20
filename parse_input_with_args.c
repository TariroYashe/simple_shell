#include "shell_header.h"

/**
* parse_input_with_args - Parse the user input into an array of command argts
* @input: The user input string
* Return: An array of strings (command arguments), or NULL on failure.
*/
char **parse_input_with_args(char *input)
{
char **args = NULL;
size_t bufsize = 64;
size_t i = 0;

args = (char **)malloc(sizeof(char *) * bufsize);
if (args == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
while (*input != '\0')
{
while (*input == ' ' || *input == '\t' || *input == '\n')
{
input++;
}
if (*input == '\0')
{
break;
}
args[i] = input;
while (*input != ' ' && *input != '\t' && *input != '\n' && *input != '\0')
{
input++;
}
args[i][input - args[i]] = '\0';
i++;
if (i >= bufsize)
{
bufsize += 64;
args = (char **)realloc(args, sizeof(char *) * bufsize);
if (args == NULL)
{
perror("realloc");
exit(EXIT_FAILURE);
}
}
}
args[i] = NULL;
return (args);
}

#include "shell_header.h"
/**
* parse_input - Parse the user input into an array of command arguments
* @input: The user input string
* Return: An array of strings (command arguments), or NULL on failure.
*/
char **parse_input(char *input)
{
char **args = NULL, *token;
size_t bufsize = 64, i = 0;
args = (char **)malloc(sizeof(char *) * bufsize);
if (args == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
token = strtok(input, " \t\n");
while (token != NULL)
{
args[i] = strdup(token);/*Duplicate the token and store it in the args array*/
if (args[i] == NULL)
{
perror("strdup");
exit(EXIT_FAILURE);
}
i++;
if (i >= bufsize)/*If we exceed the initial bufsize, reallocate memory*/
{
bufsize += 64;
args = (char **)realloc(args, sizeof(char *) * bufsize);
if (args == NULL)
{
perror("realloc");
exit(EXIT_FAILURE);
}
}
token = strtok(NULL, " \t\n");
}
args[i] = NULL;/*Set the last element to NULL to indicate the end of argmnts*/
return (args);
}


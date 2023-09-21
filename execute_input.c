#include "shell_header.h"
/**
* execute_input - Execute a command with its arguments.
* @args: An array of command arguments.
*
* Return: 0 on success, 1 on failure.
*/
int execute_input(char **args)
{
/*Check if the command is a full path to an executable*/
if (access(args[0], X_OK) == 0)
{
return (execute_command(args));
}
else
{
char *executable_path = search_executable_in_path(args);
if (executable_path != NULL)
{
int result = execute_command(args);
free(executable_path);
return (result);
}
else
{
display_error("Command not found");
return (1);
}
}
}

#include "shell_header.h"

/**
* execute_input - Execute a command with its arguments.
* @args: An array of command arguments.
*
* Return: 0 on success, 1 on failure.
*/
int execute_input(char **args)
{
pid_t child_pid;
int status;

child_pid = fork();

if (child_pid == -1)
{
display_error("fork");
return (1);
}

if (child_pid == 0)
{
/*This code runs in the child process*/
if (execve(args[0], args, NULL) == -1)
{
display_error("execve");
exit(EXIT_FAILURE);
}
}
else
{
/*This code runs in the parent process*/
waitpid(child_pid, &status, WUNTRACED);
return (0);
}

return (1); /* Return 1 in case of failure*/
}


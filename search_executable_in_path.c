#include "shell_header.h"
/**
* search_executable_in_path - Search for the executable in PATH.
* @args: An array of command arguments.
*
* Return: The constructed executable path or NULL if not found.
*/
char *search_executable_in_path(char **args)
{
/*Search for the executable in directories specified in the PATH*/
char *path = getenv("PATH");
char *path_copy = strdup(path);
char *dir = strtok(path_copy, ":");

while (dir != NULL)
{
char *executable_path = construct_executable_path(dir, args[0]);

if (access(executable_path, X_OK) == 0)
{
free(path_copy);
return (executable_path);
}

free(executable_path);
dir = strtok(NULL, ":");
}

free(path_copy);
return (NULL);
}

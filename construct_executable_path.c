#include "shell_header.h"

/**
* construct_executable_path - Construct the path to the executable.
* @dir: The directory from PATH.
* @command: The command to append to the directory.
*
* Return: The constructed path.
*/
char *construct_executable_path(const char *dir, const char *command)
{
size_t path_len = strlen(dir);
size_t command_len = strlen(command);
ssize_t n;

/*Calculate the length of the new path- +2 for '/' and null terminator*/
size_t executable_path_len = path_len + command_len + 2;

char *executable_path = (char *)malloc(executable_path_len);
if (executable_path == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}

/*Construct the new path using write*/
n = write(0, dir, path_len);
if (n == -1)
{
perror("write");
exit(EXIT_FAILURE);
}
if (dir[path_len - 1] != '/')
{
n = write(0, "/", 1);
if (n == -1)
{
perror("write");
exit(EXIT_FAILURE);
}
}
n = write(0, command, command_len);
if (n == -1)
{
perror("write");
exit(EXIT_FAILURE);
}

return (executable_path);
}

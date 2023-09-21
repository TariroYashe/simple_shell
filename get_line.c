#include "shell_header.h"

/**
* _getline - Read a line of input from the user.
*
* Return: A pointer to the input line, or NULL on failure or EOF.
*/
char *_getline(void)
{
static char buffer[READ_SIZE];
static int buffer_index;
int bytes_read = 0;
char *input = malloc(READ_SIZE);
if (input == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
while (1)
{
if (buffer_index == 0)
{
bytes_read = read(STDIN_FILENO, buffer, READ_SIZE);
if (bytes_read == -1)
{
perror("read");
free(input);
return (NULL);
}
if (bytes_read == 0)
{
free(input);
return (NULL);
}
}
while (buffer_index < bytes_read && buffer[buffer_index] != '\n')
{
*input++ = buffer[buffer_index++];
}
*input = '\0';
if (buffer_index < bytes_read && buffer[buffer_index] == '\n')
{
buffer_index++;
return (input - (buffer_index - 1));
}
}
}

#include "shell_header.h"

/**
* create_process_id - This function creates a new process using fork
* and returns the process ID (pid)
* Description: it creates new process; if an error occurs during forking,
* it handles the error and exits
*
* Return: The process ID (pid) of the newly created process
*/

pid_t create_process_id(void)
{
pid_t process_id = fork();

if (process_id == -1)
{
perror("fork");
exit(1);
}
return (process_id);
}

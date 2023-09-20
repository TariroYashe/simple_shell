#include "shell_header.h"
/**
* handle_sigint - Handle the SIGINT signal (Ctrl+C).
* @signo: The signal number.
*/
void handle_sigint(int signo)
{
(void)signo;
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n($) ", 5);
}

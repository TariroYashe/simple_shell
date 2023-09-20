#include "shell_header.h"
/**
* handle_sigstp - Handle the SIGTSTP signal (Ctrl+Z).
* @signo: The signal number.
*/
void handle_sigstp(int signo)
{
(void)signo;
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n($) ", 5);
}

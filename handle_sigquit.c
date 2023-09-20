#include "shell_header.h"

/**
* handle_sigquit - Handle the SIGQUIT signal (Ctrl+\).
* @signo: The signal number.
*/
void handle_sigquit(int signo)
{
(void)signo;
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
}

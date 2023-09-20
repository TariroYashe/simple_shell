#include "shell_header.h"

/**
 * signal_handler - Handle signals received by the shell
 * @signum: The signal number received
 *
 * Description:
 * This function is a signal handler that handles specific signals
 * received by the shell, such as SIGINT (Ctrl+C) and SIGCHLD (child
 * process termination).
 */
void signal_handler(int signum)
{
if (signum == SIGINT)
{
shell_print("\n");
display_prompt();
}
else if (signum == SIGCHLD)
{
int status;
pid_t child_pid;
while ((child_pid = waitpid(-1, &status, WNOHANG)) > 0)
{
}
}
}



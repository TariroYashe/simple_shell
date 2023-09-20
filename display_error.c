#include "shell_header.h"
/**
 * display_error - Display an error message.
 * @msg: The error message to display.
 */
void display_error(char *msg)
{
perror(msg);
}

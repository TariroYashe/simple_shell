#include "shell_header.h"

/**
 * display_prompt - func that prints the prompt "Simple_Shell$ "
 * fflush - func that flush the output buffer to ensure the prompt is displayed
 * shell_print - func to print the string to stdout
*/

void display_prompt(void)
{
shell_print("Simple_Shell$ ");
fflush(stdout);
}

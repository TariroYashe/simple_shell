#include "shell_header.h"

/**
 * shell_print - Write function to print the string to stdout (fd1)
 * @letters: Pointer to the string we want to print
 *
 * Description:
 * This function writes the given string to the standard output (stdout).
 *
 * @letters: Pointer to the null-terminated string to be printed.
 */

void shell_print(const char *letters)
{
	write(1, letters, strlen(letters));
}


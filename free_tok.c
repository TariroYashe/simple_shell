#include "shell_header.h"

/**
* free_tok - Free the memory allocated for an array of strings.
* @tokens: The array of strings to free.
*/
void free_tok(char **tokens)
{
int i;
if (tokens)
{
for (i = 0; tokens[i]; i++)
free(tokens[i]);
free(tokens);
}
}

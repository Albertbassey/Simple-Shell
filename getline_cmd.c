#include "shell.h"

/**
 * _getline_cmd -  gets inputs
 *
 * Return: returns input.
 */

char *_getline_cmd(void)
{
	char *lineptr = NULL;
	size_t char_user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "Albertshell$$ ", 14);

	if (getline(&lineptr, &char_user, stdin) == -1)
	{
		free(lineptr);
		return (NULL);
	}

	return (lineptr);
}

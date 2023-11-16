#include "shell.h"


/**
 * _get_env - prints envir to standard output
 *
 * @envir: environment
 */

void _get_env(char **envir)
{
	size_t move = 0;

	while (envir[move])
	{
		write(STDOUT_FILENO, envir[move], _strlen(envir[move]));
		write(STDOUT_FILENO, "\n", 1);
		move++;
	}
}

#include "shell.h"

/**
 * _getpath - get variable path.
 * @envir: enviroment local
 *
 * Return: returns path.
 */

char *_getpath(char **envir)
{
	size_t index = 0, my_var = 0, count = 5;
	char *path = NULL;

	for (index = 0; _strncmp(envir[index], "path=", 5); index++)
		;
	if (envir[index] == NULL)
		return (NULL);

	for (count = 5; envir[index][my_var]; my_var++, count++)
		;
	path = malloc(sizeof(char) * (count + 1));

	if (path == NULL)
		return (NULL);

	for (my_var = 5, count = 0; envir[index][my_var]; my_var++, count++)
		path[count] = envir[index][my_var];

	path[count] = '\0';
	return (path);
}

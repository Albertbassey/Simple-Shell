#include "shell.h"

/**
 * _vals_path - Separate the path in new strings.
 * @arg: Command input of user.
 *
 * @envir: Enviroment.
 *
 * Return: Ptr to strings.
 */

int _vals_path(char **arg, char **envir)
{
	char *token = NULL, *path_rel = NULL, *path_absol = NULL;
	size_t value_path, len;
	struct stat stat_lineptr;

	if (stat(*arg, &stat_lineptr) == 0)
		return (-1);
	path_rel = _getpath(envir);
	if (!path_rel)
		return (-1);
	token = strtok(path_rel, ":");
	len = _strlen(*arg);
	while (token)
	{
		value_path = _strlen(token);
		path_absol = malloc(sizeof(char) * (value_path + len + 2));
		if (!path_absol)
		{
			free(path_rel);
			return (-1);
		}
		path_absol = strcpy(path_absol, token);
		_strcat(path_absol, "/");
		_strcat(path_absol, *arg);

		if (stat(path_absol, &stat_lineptr) == 0)
		{
			*arg = path_absol;
			free(path_rel);
			return (0);
		}
		free(path_absol);
		token = strtok(NULL, ":");
	}
	token = '\0';
	free(path_rel);
	return (-1);
}

#include "shell.h"

/**
 * tokenize - tokenizes  string.
 * @lineptr: user input
 *
 * Return: ptr to array of pointers.
 */

char **tokenize(char *lineptr)
{
	char **user_cmd = NULL;
	char *token = NULL;
	int size = 0;
	size_t j = 0;

	if (lineptr == NULL)
		return (NULL);

	for (j = 0; lineptr[j]; j++)
	{
		if (lineptr[j] == ' ')
			size++;
	}
	if ((size + 1) == _strlen(lineptr))
		return (NULL);
	user_cmd = malloc(sizeof(char *) * (size + 2));
	if (user_cmd == NULL)
		return (NULL);

	token = strtok(lineptr, " \n\t\r");

	for (j = 0; token != NULL; j++)
	{
		user_cmd[j] = token;
		token = strtok(NULL, " \n\t\r");
	}
	user_cmd[j] = NULL;
	return (user_cmd);
}

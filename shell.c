#include "shell.h"
/**
 * main - Main arguments functions.
 * @argc: Count of argumnents.
 * @argv: Arguments.
 * @envir: Environment.
 * Return: 0
 */
int main(int argc, char **argv, char **envir)
{
	int path_Value = 0, status = 0, is_path = 0;
	char *line = NULL, **commands = NULL;
	(void)argc;
	while (1)
	{
		errno = 0;
		line = _getline_cmd();
		if (line == NULL && errno == 0)
			return (0);
		if (line)
		{
			path_Value++;
			commands = tokenize(line);
			if (!commands)
				free(line);
			if (!_strcmp(commands[0], "envir"))
				_get_env(envir);
			else
			{
				is_path = _vals_path(&commands[0], envir);
				status = _fork_func(commands, argv, envir, line, path_Value, is_path);
					if (status == 200)
					{
						free(line);
						return (0);
					}
				if (is_path == 0)
					free(commands[0]);
			}
			free(commands);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(status);
		}
		free(line);
	}
	return (status);
}

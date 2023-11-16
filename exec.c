#include "shell.h"

int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int lsh_ctrld(char **args);

/*
 * list of builtin commands, followed by their functions.
 */

char *builtin_str[] = {"cd", "help", "exit", "^D"};

int (*builtin_func[]) (char **) = {&lsh_cd, &lsh_help, &lsh_exit, &lsh_ctrld};

/**
 * lsh_num_builtins - size.
 * Return: size.
 */

int lsh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * lsh_cd - builtin to change dirs.
 * @args: list of arguments.  args[0] is "cd".  args[1] is the dir.
 * Return: 1 on success.
 */

int lsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}

/**
 * lsh_help - print help for shell
 * @args: list of args.
 * Return: 1 Always.
 */

int lsh_help(char **args)
{
	int j;

	printf("Albertbassey simple shell\n");
	printf("If you need assistance, reach out via my github\n");
	(void)args;
	for (j = 0; j < lsh_num_builtins(); j++)
	{
		printf("  %s\n", builtin_str[j]);
	}

	return (1);
}

/**
 * lsh_exit - builtin to exit shell
 * @args: list of arguments.
 * Return: 0 Always.
 */

int lsh_exit(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 * lsh_ctrld - builtin to handle "^D" call.
 * @args: List of argumennts.
 * Return: Always returns 0.
 */

int lsh_ctrld(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 *_fork_func - foo that creates a fork.
 *@arg: Command and vals path.
 *@av: the name of our program.
 *@envir: Environment.
 *@lineptr: Command line for user.
 *@np: ID of proces.
 *@c: Checker add new test.
 *Return: 0 success.
 */

int _fork_func(char **arg, char **av, char **envir,
		char *lineptr, int np, int c)
{

	pid_t child_pid;
	int status, j = 0;
	char *format = "%s: %d: %s: not found\n";

	if (arg[0] == NULL)
		return (1);
	for (j = 0; j < lsh_num_builtins(); j++)
	{
		if (_strcmp(arg[0], builtin_str[j]) == 0)
			return (builtin_func[j](arg));
	}
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(arg[0], arg, envir) == -1)
		{
			fprintf(stderr, format, av[0], np, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(lineptr);
			exit(errno);
		}
	}
	else
	{
		wait(&status);
		return (status);
	}
	return (0);
}

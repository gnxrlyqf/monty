#include "main.h"

/**
 * check - checks if command is a builtin
 * @cmd: command
 * @env: environment
 *
 * Return: 1 for exit, 0 for env, -1 for neither
 **/

int check(char **cmd, char **env)
{
	int ex;

	if (_strcmp(cmd[0], "exit") == 0)
	{
		if (cmd[1] != NULL)
		{
			ex = _atoi(cmd[1]);
			return (ex);
		}
		return (0);
	}
	else if (_strcmp(cmd[0], "env") == 0)
	{
		if (!cmd[1])
			printenv(env);
		return (-2);
	}
	else
		return (-1);
}

/**
 * printenv - prints the environment
 * @env: environment
 **/

void printenv(char **env)
{
	char **envir;

	envir = env;
	while (*envir != NULL)
	{
		write(1, *envir, _strlen(*envir));
		write(1, "\n", 1);
		envir++;
	}
}

#include "main.h"

/**
 * main - simple shell
 * @ac: arg number
 * @av: arg array
 * @envp: current environment
 * Return: it's a loop
 */

int main(int ac, char **av, char **envp)
{
	int builtin, i;
	size_t size = 1024;
	ssize_t ret;
	char *buffer, *argv[20], *token;

	if (ac != 1)
		return (-1);
	while (1)
	{
		buffer = malloc(1024);
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		ret = getline(&buffer, &size, stdin);
		if (ret == -1)
			write(1, "\n", 1), exit(2);
		token = strtok(buffer, " \n");
		i = 0;
		while (token)
		{
			argv[i] = token;
			token = strtok(NULL, " \n");
			i++;
		}
		free(buffer);
		if (!argv[0])
			continue;
		builtin = check(argv, envp);
		if (builtin != -1)
		{
			if (builtin > -1)
				exit(builtin);
			continue;
		}
		if (exec(argv, av[0], envp) == -1)
			continue;
	}
	return (0);
}

#include "monty.h"

/**
 * is_number - check the string is number
 * @s: string
 * Return: 1if is number or 0 if not
 */

int is_number(char *s)
{
	int i = 0;

	while (*(s + i))
	{
		if (*(s + i) <= 57 && *(s + i) >= 48)
			i++;
		else
			return (0);
	}
	return (1);
}
/**
 * cmd - split command in array
 * @buffer: command line
 * Return: split string
 */

char **cmd(char *buffer)
{
	char *token = NULL;
	int i = 0;
	char **cmd = malloc(sizeof(char *) * 256);

	token = strtok(buffer, " \t\n");
	while (token)
	{
		cmd[i] = token;
		i++;
		token = strtok(NULL, " \t\n");
	}
	if (cmd[1] && !is_number(cmd[1]))
	{
		write(STDERR_FILENO, "L<line_number>: usage: push integer\n", 36);
		free(buffer);
		exit(EXIT_FAILURE);
	}
	return (cmd);
}

#include "main.h"
#include <unistd.h>
#include <stdlib.h>

char **cmd(char *buffer)
{
	int size, i, space;
	char **cmd = malloc(sizeof(char *) * 2);

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == ' ')
			space = i;
		i++;
	}
	size = i;
	cmd[0] = malloc(sizeof(char) * (space + 1));
	cmd[1] = malloc(sizeof(char) * (size - space));
	i = 0;
	while (buffer[i] != ' ')
	{
		cmd[0][i] = buffer[i];
		i++;
	}
	i = 0;
	while (buffer[space + 1] != '\0')
	{
		if(!(buffer[space + 1] >= '0' && buffer[space + 1] <= '9'))
		{
			write(STDERR_FILENO, "L<line_number>: usage: push integer\n", 36);
			exit(EXIT_FAILURE);
		}
		cmd[1][i] = buffer[space + 1];
		space++, i++;
	}
	return (cmd);
}
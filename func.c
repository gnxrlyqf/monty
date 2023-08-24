#include "monty.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char **cmd(char *buffer)
{
	int i, size;
	char **cmd = malloc(sizeof(char *) * 2);

	i = 0;
	while (buffer[i] != '\0')
		i++;
	size = i;
	cmd[0] = strtok(buffer, " \0\n");
	if (!cmd[0])
		return (NULL);
	if (cmd[0][strlen(cmd[0]) - 1] == '\n')
	{
		cmd[0][size - 1] = '\0';
		cmd[1] = NULL;
		return (cmd);
	}
	cmd[1] = strtok(NULL, " \0\n");
	if (cmd[1][strlen(cmd[1]) - 1] == '\n')
		cmd[1][strlen(cmd[1]) - 1] = '\0';
	return (cmd);
}

instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	/*{"pint", pint}
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop}*/
};

void exec(char **arr, stack_t *stack, int line_num)
{
	int i = 0, n, found = 0;

	if (strcmp(arr[0], "push") == 0 && arr[1])
	{
		for(i = 0; (long unsigned int)i < strlen(arr[1]); i++)
		{
			if (!(arr[1][i] <= '9' && arr[1][i] >= '0'))
				fprintf(stderr, "L%d: usage: push integer\n", line_num), exit(EXIT_FAILURE);
		}
		n = atoi(arr[1]);
	}
	for (i = 0; i < 2; i++)
	{
		if (strcmp(arr[0], (instructions[i]).opcode) == 0)
		{
			printf("%s - %s\n", arr[0], instructions[i].opcode);
			(instructions[i]).f(&stack, (unsigned int)n);
			found = 1;
			break;
		}
	}
	if (!found)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, arr[0]);
		exit(EXIT_FAILURE);
	}
}

#include "monty.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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
 * cmd - creates command out of buffer
 * @buffer: text to convert
 *
 * Return: array of strings with command and number
*/

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
	if (strlen(cmd[0]) == (unsigned long int)size)
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
	/*
	* {"pint", pint}
	* {"pop", pop},
	* {"swap", swap},
	* {"add", add},
	* {"nop", nop}
	*/
};

/**
 * exec - executes an instruction
 * @arr: instruction to execute
 * @stack: pointer to pointer to the top of the stack
 * @line_num: line number
*/

void exec(char **arr, stack_t **stack, int line_num)
{
	int i = 0, n, found = 0;

	if (strcmp(arr[0], "push") == 0)
	{
		if (!arr[1] || is_number(arr[1]) != 1)
			fprintf(stderr, "L%d: usage: push integer\n", line_num), exit(EXIT_FAILURE);
		n = atoi(arr[1]);
	}
	for (i = 0; i < 2; i++)
	{
		if (strcmp(arr[0], instructions[i].opcode) == 0)
		{
			(instructions[i]).f(stack, (unsigned int)n);
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

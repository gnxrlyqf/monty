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
 * @line_num: line number
 * Return: nothing
*/

void cmd(char *buffer, int line_num)
{
	char *token = NULL;
	int i = 0;

	token = strtok(buffer, " \t\n");
	while (token)
	{
		var_glb.cmd[i] = token;
		i++;
		token = strtok(NULL, " \t\n");
	}
	var_glb.cmd[i] = "\0";
	if (i >= 3 && !is_number(var_glb.cmd[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		_free();
		exit(EXIT_FAILURE);
	}
}

/**
 * get_inst - get the fonction of instruction
 * @opc: opcode
 * Return: opcode fonction
 */
void (*get_inst(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode; i++)
		if (strcmp(opc, (instructions[i]).opcode) == 0)
			return (instructions[i].f);
	return (NULL);
}

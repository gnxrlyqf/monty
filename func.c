#include "monty.h"


/**
 * is_number - check the string is number
 * @s: string
 * Return: 1if is number or 0 if not
*/

int is_number(char *s)
{
	int i = 0;

	if (s[0] == 45)
		i++;
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
 * Return: nothing
*/

void cmd(char *buffer)
{
	char *token = NULL;
	int i = 0;

	token = strtok(buffer, " \t\n");
	while (token)
	{
		v_glb.cmd[i] = token;
		i++;
		token = strtok(NULL, " \t\n");
	}
	v_glb.cmd[i] = "\0";
}

/**
 * exec - executes an instruction
 * @arr: instruction to execute
 * @stack: pointer to pointer to the top of the stack
 * @line_num: line number
*/
void exec(int line_num)
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
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
	};
	int i, n, found = 0;

	for (i = 0; instructions[i].opcode; i++)
		if (strcmp(v_glb.cmd[0], (instructions[i]).opcode) == 0)
		{
			if (strcmp(v_glb.cmd[0], "push") == 0)
			{
				if (!v_glb.cmd[1] || is_number(v_glb.cmd[1]) != 1)
				{
					_free();
					fprintf(stderr, "L%d: usage: push integer\n",
							line_num);
					exit(EXIT_FAILURE);
				}
				n = atoi(v_glb.cmd[1]);
				(instructions[i]).f(&v_glb.stack,
						(unsigned int)n);
			}
			else
				(instructions[i]).f(&v_glb.stack,
						(unsigned int)line_num);
			found = 1;
			break;
		}
	if (!found)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				line_num, v_glb.cmd[0]);
		_free();
		exit(EXIT_FAILURE);
	}
}

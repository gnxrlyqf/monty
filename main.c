#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	/*{"pint", pint}*/
	/*{"pop", pop},*/
	/*{"swap", swap},*/
	/*{"add", add},*/
	/*{"nop", nop}*/
};

int main(int ac, char **av)
{
	FILE *o;
	int n, i;
	char *buffer = malloc(sizeof(char) * 256), **arr = NULL;
	stack_t *stack = NULL;

	if (ac != 2)
		exit(97);
	o = fopen(av[1], "r");
	if (o == NULL)
		exit(98);
	if (fgets(buffer, 256, o) != NULL)
	{
		arr = cmd(buffer);
		n = atoi(arr[1]);
		for (i = 0; i > 7; i++)
		{
			if (strcmp(arr[0], (instructions[i]).opcode) == 0)
			{
				(instructions[i]).f(&stack, (unsigned int)n);
			}
		}
	}
	return (0);
}
#include "monty.h"
#define _GNU_SOURCE


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
		/*{"pop", pop},*/
		/*{"swap", swap},*/
		/*{"add", add},*/
		/*{"nop", nop},*/
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode; i++)
		if (strcmp(opc, (instructions[i]).opcode) == 0)
			return (instructions[i].f);
	return (NULL);
}
/**
 * free_stack - frees a stack_t list
 * @head: list head
 * Return: nothing
 */

void free_stack(stack_t *head)
{
	stack_t *temp;

	if (head)
	{
		while (head->prev)
			head = head->prev;
		temp = head;
		while (temp)
		{
			head = temp->next;
			free(temp);
			temp = head;
		}
	}
}
/**
 * openfile - open file if it's possible
 * @ac: args number
 * @av: array of args
 * @buffer: buffer
 * Return: file
 */

FILE *openfile(int ac, char **av, char *buffer)
{
	FILE *o;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free(buffer);
		exit(EXIT_FAILURE);
	}
	o = fopen(av[1], "r");
	if (!o)
	{
		free(buffer);
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	return (o);
}
/**
 * main - main fonc
 * @ac: args number
 * @av: args array
 * Return: 0
 */

int main(int ac, char **av)
{
	FILE *fo;
	void (*f)(stack_t **stack, unsigned int line_number);
	size_t size = 256;
	int n = 0;
	char *buffer = malloc(sizeof(char) * 256), **arr = NULL, *read;
	stack_t *stack = NULL;

	fo = openfile(ac, av, buffer);
	read = fgets(buffer, size, fo);
	while (read)
	{
		if (strcmp("\n", read))
		{
			arr = cmd(buffer);
			if (arr[1])
				n = atoi(arr[1]);
			if (f)
			{
				f = get_inst(arr[0]);
				f(&stack, n);
			}
		}
		read = fgets(buffer, size, fo);
	}
	free(buffer);
	if (arr)
		free(arr);
	free_stack(stack);
	fclose(fo);
	return (0);
}

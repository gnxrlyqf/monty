#include "monty.h"

instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	/*{"pint", pint}*/
	/*{"pop", pop},*/
	/*{"swap", swap},*/
	/*{"add", add},*/
	/*{"nop", nop},*/
	{NULL, NULL}
};
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
int main(int ac, char **av)
{
	FILE *fo;
	size_t size = 256;
	int n = 0, i;
	char *buffer = malloc(sizeof(char) * 256), **arr = NULL, *read;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free(buffer);
		exit(EXIT_FAILURE);
	}
	fo = fopen(av[1], "r");
	if (!fo)
	{
		free(buffer);
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	read = fgets(buffer, size, fo);
	while (read)
	{
		if (strcmp("\n", read))
		{
			arr = cmd(buffer);
			if (arr[1])
				n = atoi(arr[1]);
			for (i = 0; instructions[i].opcode; i++)
			{
				if (strcmp(arr[0], (instructions[i]).opcode) == 0)
				{
					(instructions[i]).f(&stack, (unsigned int)n);
					break;
				}
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

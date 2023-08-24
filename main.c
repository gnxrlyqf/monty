#include "monty.h"
#define _GNU_SOURCE

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
	size_t size = 256;
	int num = 1;
	char *buffer = malloc(sizeof(char) * 256), **arr = NULL;
	stack_t *stack = NULL;

	memset(buffer, '\0', 256);
	fo = openfile(ac, av, buffer);
	while (fgets(buffer, size, fo))
	{
		if (strcmp("\n", buffer) == 0)
		{
			num++;
			continue;
		}
		arr = cmd(buffer);
		exec(arr, &stack, num);
		memset(buffer, '\0', 256);
		num++;
	}
	free(buffer);
	if (arr)
		free(arr);
	free_stack(stack);
	fclose(fo);
	return (0);
}

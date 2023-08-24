#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *elem = malloc(sizeof(stack_t)), *temp;

	if (!elem)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	elem->n = line_number;

	if (!*stack)
	{
                elem->next = *stack;
		elem->prev = NULL;
		*stack = elem;
	}
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		elem->next = temp->next;
		elem->prev = temp;
		temp->next = elem;
	}
}

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current;

	if (*stack)
	{
		current = *stack;
		while (current->next)
			current = current->next;
		while (current)
		{
			printf("%d\n", current->n);
			current = current->prev;
		}
	}
}

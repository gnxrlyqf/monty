#include "main.h"
#include <stdlib.h>
#include <stdio.h>

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *elem = malloc(sizeof(stack_t));

	if (!elem)
		exit(EXIT_FAILURE);

	elem->n = line_number;
	elem->prev = NULL;
	if(!stack)
		elem->next = NULL;
	else
		(*stack)->prev = elem;
	elem->next = *stack;
	*stack = elem;
}

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current = *stack;

	if (!current)
		exit(EXIT_FAILURE);
	
	while(current->next)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
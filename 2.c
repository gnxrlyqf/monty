#include "monty.h"


/**
 * add - adds the top two elements of the stack.
 * @stack: head stack
 * @line_number: void
 * Return: nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *remove;

	if (!(*stack) || ((*stack)->next && (*stack)->prev))
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		_free();
		exit(EXIT_FAILURE);
	}

	while ((*stack)->next)
		*stack = (*stack)->next;

	(*stack)->prev->n = (*stack)->n + (*stack)->prev->n;
	remove = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	free(remove);
}

/**
 * nop - doesn’t do anything.
 * @stack: head stack
 * @line_number: void
 * Return: nothing
 */

void nop(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
}

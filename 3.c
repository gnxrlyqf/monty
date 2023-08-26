#include "monty.h"

/**
 * mod - computes the rest of the division
 * of the second top element of the stack by
 * the top element of the stack.
 * @stack: head stack
 * @line_number: void
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *remove;

	if (!(*stack) || (!(*stack)->next && !(*stack)->prev))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		_free();
		exit(EXIT_FAILURE);
	}

	while ((*stack)->next)
		*stack = (*stack)->next;

	(*stack)->prev->n = (*stack)->prev->n % (*stack)->n;
	remove = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	free(remove);
}

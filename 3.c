#include "monty.h"

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *remove;

	if (!(*stack) || ((*stack)->next && (*stack)->prev))
	{
		fprintf(stderr, "L%d: can't div, stack too short", line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by 0", line_number);
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

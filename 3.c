#include "monty.h"

/**
 * mod - computes the rest of the division
 * of the second top element of the stack by
 * the top element of the stack.
 * @stack: head stack
 * @line_number: line number
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

/**
 * pchar - prints the char at the top of the stack
 * @stack: head stack
 * @line_number: line number
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

}

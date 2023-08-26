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

	if (!(*stack) || (!(*stack)->next && !(*stack)->prev))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
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
/**
 * sub - subtracts the top two elements of the stack.
 * @stack: head stack
 * @line_number: void
 * Return: nothing
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *remove;

	if (!(*stack) || ((*stack)->next && (*stack)->prev))
	{
		fprintf(stderr, "L%d: can't sub, stack too short", line_number);
		_free();
		exit(EXIT_FAILURE);
	}

	while ((*stack)->next)
		*stack = (*stack)->next;

	(*stack)->prev->n = (*stack)->prev->n - (*stack)->n;
	remove = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	free(remove);
}

/**
 * divide - divides the top two elements of the stack.
 * @stack: head stack
 * @line_number: void
 * Return: nothing
 */

void divide(stack_t **stack, unsigned int line_number)
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

	(*stack)->prev->n = (*stack)->prev->n / (*stack)->n;
	remove = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	free(remove);
}

/**
 * mul - multiplies the top two elements of the stack.
 * @stack: head stack
 * @line_number: void
 * Return: nothing
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *remove;

	if (!(*stack) || ((*stack)->next && (*stack)->prev))
	{
		fprintf(stderr, "L%d: can't mul, stack too short", line_number);
		_free();
		exit(EXIT_FAILURE);
	}

	while ((*stack)->next)
		*stack = (*stack)->next;

	(*stack)->prev->n = (*stack)->prev->n * (*stack)->n;
	remove = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	free(remove);
}

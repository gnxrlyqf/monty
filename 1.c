#include "monty.h"
/**
 * push - push fonction to insert new element in stack LIFO
 * @stack: head stack
 * @line_number: data n
 * Return: nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *elem = malloc(sizeof(stack_t)), *temp = NULL;

	if (!elem)
	{
		fprintf(stderr, "Error: malloc failed\n");
		_free();
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
		while ((*stack)->next)
			*stack = (*stack)->next;
		temp = *stack;
		elem->next = temp->next;
		elem->prev = temp;
		temp->next = elem;
		*stack = elem;
	}
}
/**
 * pall - pall fonction to display elements in stack LIFO
 * @stack: head stack
 * @line_number: void
 * Return: nothing
 */

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current = NULL;

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
/**
 * pint - prints the value at the top of the stack,
 * followed by a new line.
 * @stack: head stack
 * @line_number: void
 * Return: nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack)
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		printf("%d\n", temp->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		_free();
		exit(EXIT_FAILURE);
	}

}
/**
 * swap - swaps the top two elements of the stack.
 * @stack: head stack
 * @line_number: void
 * Return: nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *tempt;

	if (!*stack || (!(*stack)->next && !(*stack)->prev))
	{
		_free();
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while ((*stack)->next)
		*stack = (*stack)->next;
	temp = *stack;
	tempt = temp->prev;
	temp->prev = tempt->prev;
	tempt->next = NULL;
	temp->next = tempt;
	tempt->prev = temp;
	if (temp->prev)
		temp->prev->next = temp;
	*stack = tempt;
}

/**
 * pop - removes the top element of the stack.
 * @stack: head stack
 * @line_number: void
 * Return: nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *remove;

	if (!(*stack))
	{
		_free();
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	while ((*stack)->next)
		*stack = (*stack)->next;
	remove = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	free(remove);
}


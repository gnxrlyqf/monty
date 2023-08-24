#include "monty.h"
/**
 * push - push fonction to insert new element in stack LIFO
 * @stack: head stack
 * @line_number: data n
 * Return: nothing
 */

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
/**
 * pall - pall fonction to display elements in stack LIFO
 * @stack: head stack
 * @line_number: void
 * Return: nothing
 */

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
/**
 * pint - prints the value at the top of the stack,
 * followed by a new line.
 * @stack: head stack
 * @line_number: void
 * Return: nothing
 */

void pint(stack_t **stack, __attribute__((unused)) unsigned int line_number)
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
		fprintf(stderr, "L<line_number>: can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
}

void pop(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *remove;

	if (!(*stack))
		exit(EXIT_FAILURE);
	remove = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(remove);
}


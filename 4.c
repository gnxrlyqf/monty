#include "monty.h"



/**
 * stack - sets the format of the data to a stack (LIFO).
 * @stack: head stack
 * @line_number: line number
 * Return: nothing
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void) **stack;
	(void) line_number;

	if (!v_glb.lifo)
		v_glb.lifo = 1;
}


/**
 * queue - sets the format of the data to a queue (FIFO).
 * @stack: head stack
 * @line_number: line number
 * Return: nothing
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) **stack;
	(void) line_number;

	if (v_glb.lifo)
		v_glb.lifo = 0;

}

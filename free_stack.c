#include "monty.h"

/**
 * free_stack - frees a stack_t list
 * @head: list head
 * Return: nothing
 */

void free_stack(stack_t *head)
{
	stack_t *temp;

	if (head)
	{
		while (head->prev)
			head = head->prev;
		temp = head;
		while (temp)
		{
			head = temp->next;
			free(temp);
			temp = head;
		}
	}
}
/**
 * _free - free memory allocat
 * Return: nothing
 */
void _free(void)
{
	free(var_glb.buffer);
	free(var_glb.cmd);
	free_stack(var_glb.stack);
	fclose(var_glb.fd);
}

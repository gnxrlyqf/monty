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
	free(v_glb.buffer);
	free(v_glb.cmd);
	free_stack(v_glb.stack);
	fclose(v_glb.fd);
}

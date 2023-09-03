#include "main.h"
/**
 * free_list - frees linked list
 * @head: beginning of linked list
 * Return: nothing
 */
void free_list(linked *head)
{
	linked *temp;

	if (head)
	{
		temp = head;
		while (temp)
		{
			head = temp->next;
			free(temp->dir);
			free(temp);
			temp = head;
		}
	}
}

/**
 * add_node_end - adds new node to end of linked list
 * @head: beginning of linked list
 * @str: new string to be added to linked list
 * Return: pointer to new node
 */
linked *add_node_end(linked **head, char *str)
{
	linked *temp, *new_node;

	new_node = malloc(sizeof(linked));
	if (!new_node)
		return (NULL);
	new_node->dir = _strdup(str);
	new_node->next = NULL;
	if (!*head)
		*head = new_node;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
	temp = NULL;
	return (new_node);
}
/**
 * pathlist - create a list of directory in path
 * @head: head of list
 * @path: path value
 *
 * Return: head of list
 */

linked *pathlist(linked *head, char *path)
{
	char *dirr[20], *token;
	int i = 0;

	token = strtok(path, ":\n");
	while (token)
	{
		dirr[i] = token;
		i++;
		token = strtok(NULL, ":\n");
	}
	i = 0;
	while (dirr[i])
	{
		add_node_end(&head, dirr[i]);
		i++;
	}
	return (head);
}

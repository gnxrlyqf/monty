#include "main.h"

/**
 * _which - find path of filename
 * @filename: name of file
 * @progname: name of programme
 * @envp: environment
 *
 * Return: path of filename
 */

char *_which(char *filename, char *progname, char **envp)
{
	struct stat st;
	unsigned int j, k, dirlen, filelen;
	char *check = NULL, *PATH = _getenv("PATH", envp);
	linked *head = NULL, *temp = NULL;

	head = pathlist(head, PATH);
	free(PATH);
	temp = head;
	filelen = _strlen(filename);
	while (temp)
	{
		dirlen = _strlen(temp->dir);
		check = malloc(sizeof(char) * (dirlen + filelen + 1));
		if (!check)
			return (NULL);
		j = 0;
		while (temp->dir[j])
			check[j] = temp->dir[j], j++;
		check[j] = '/', j++, k = 0;
		while (filename[k])
			check[j] = filename[k], k++, j++;
		if (stat(check, &st) == 0)
		{
			free_list(head);
			head = NULL, temp = NULL;
			return (check);
		}
		free(check);
		temp = temp->next;
	}
	free_list(head);
	head = NULL, temp = NULL;
	if (!isatty(STDIN_FILENO))
		error_non_inter(filename, progname);
	else
	{
		write(1, filename, filelen);
		write(1, ": command not found\n", 20);
	}
	return (NULL);
}

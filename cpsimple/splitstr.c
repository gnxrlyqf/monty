#include "main.h"

/**
 * _realloc - reallocates a memory block
 * @ptr:  pointer to the memory previously allocated
 * @old_size: size of the allocated space for ptr
 * @new_size: size of the new memory block
 * Return: pointer
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned int i = 0;

	if (old_size == new_size)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(new_size);
		free(ptr);
		return (p);
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	while (i < old_size && i < new_size)
	{
		p[i] = ((char *)ptr)[i];
		i++;
	}
	free(ptr);
	return (p);
}

/**
 * free_grid - frees a 2 dimensional grid previously created
 * @grid: grid
 * Return: nothing
 */
void free_grid(char **grid)
{
	int i = 0;

	while (grid[i])
		i++;
	for (--i; i >= 0; i--)
		free(grid[i]);
	free(grid);
}
/**
 * splitstr - splits a string
 * @buffer: the string
 * @idf: the characters whene we splits the string
 *
 * Return: an array of each word of the string
 **/

char **splitstr(char *buffer, char *idf)
{
	unsigned int i = 0, j, k, l = 0, a = 0, b = 0;
	char **arr = NULL, *temp = NULL;

	temp = buffer;
	i = 0;
	while (temp[i])
	{
		j = 0;
		while (idf[j])
		{
			if (temp[i] == idf[j])
			{
				l = l + a, k = 0;
				if (l < i)
				{
					arr = _realloc(arr, b, (b + 1));
					while (l < i)
					{
						arr[b] = _realloc(arr[b], k, (k + 1));
						arr[b][k] = temp[l];
						k++, l++;
					}
					arr[b] = _realloc(arr[b], k, (k + 1));
					arr[b][k] = '\0';
					b++;
				}
				a = 1;
				break;
			}
			j++;
		}
		i++;
	}
	arr[b] = NULL;
	return (arr);
}

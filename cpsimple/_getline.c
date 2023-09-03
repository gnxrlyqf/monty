#include "main.h"

/**
 * _getline - reads input from user
 * @line: buffer to write to
 * @n: max number of lines to read
 * fd: stream to read from
 *
 * Return: number of chars read, or 0 if \n or OEF is encountered
 **/

ssize_t _getline(char **line, size_t *n, int fd)
{
	size_t r;

	if (*n < 128)
		*n = 128;
	*line = malloc(*n * sizeof(char));
	if (*line == NULL)
	{
		return (-1);
	}
	r = read(fd, *line, *n);
	if (r == 0)
	{
		return (r);
	}
	if (_strchr(*line, '\n') != NULL)
		return (r);
	write(1, "\n", 1);
	return (r);
}

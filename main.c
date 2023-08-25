#include "monty.h"
var_g v_glb;

/**
 * set_start - initial global variables
 * @f: file discr
 * Return: nothing
 */

void set_start(FILE *f)
{
	v_glb.stack = NULL;
	v_glb.fd = f;
	v_glb.buffer = malloc(sizeof(char) * 256);
	v_glb.cmd = malloc(256);
}
/**
 * openfile - open file if it's possible
 * @ac: args number
 * @av: array of args
 * Return: file
 */

FILE *openfile(int ac, char **av)
{
	FILE *o;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free(v_glb.buffer);
		free(v_glb.cmd);
		exit(EXIT_FAILURE);
	}
	o = fopen(av[1], "r");
	if (!o)
	{
		free(v_glb.buffer);
		free(v_glb.cmd);
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	return (o);
}
/**
 * main - main fonc
 * @ac: args number
 * @av: args array
 * Return: 0
 */

int main(int ac, char **av)
{
	FILE *fo;
	void (*f)(stack_t **stack, unsigned int line_number);
	size_t size = 256;
	int num = 1, n;
	char *read = NULL;

	fo = openfile(ac, av);
	set_start(fo);
	read = fgets(v_glb.buffer, size, fo);
	while (read)
	{
		cmd(v_glb.buffer, num);
		if (strcmp(v_glb.cmd[0], "\0"))
		{
			f = get_inst(v_glb.cmd[0]);
			if (f)
			{
				if (v_glb.cmd[1])
					n = num, num = atoi(v_glb.cmd[1]), f(&v_glb.stack, num), num = n;
				else
					f(&v_glb.stack, num);
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n",
						num, v_glb.cmd[0]);
				_free();
				exit(EXIT_FAILURE);
			}
		}
		read = fgets(v_glb.buffer, size, fo), num++;
	}
	_free();
	return (0);
}

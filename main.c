#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	/*{"pint", pint}*/
	/*{"pop", pop},*/
	/*{"swap", swap},*/
	/*{"add", add},*/
	/*{"nop", nop}*/
};

int main(int ac, char **av)
{
	FILE *o;
	char *buffer = malloc(sizeof(char) * 256), **arr = NULL;

	if (ac != 2)
		exit(97);
	o = fopen(av[1], "r");
	if (o == NULL)
		exit(98);
	if (fgets(buffer, 256, o) != NULL)
	{
		arr = cmd(buffer);
		printf("%s - %s\n", arr[0], arr[1]);
	}
	return (0);
}
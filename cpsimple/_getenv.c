#include "main.h"
/**
 * _getenv - get value of name in environ
 * @name: name of value
 * @environ: environment
 *
 * Return: pointer to value of name
 */

char *_getenv(const char *name, char **environ)
{
	unsigned int i = 0, j, k = 0, m = 0;
	char *value;

	while (environ[i])
	{
		j = 0;
		while (environ[i][j] == name[j])
		{
			if (environ[i][j + 1] == '=')
			{
				j += 2;
				m = j;
				k = 0;
				while (environ[i][m])
					m++, k++;
				value = malloc(sizeof(char) * k);
				m = 0;
				while (environ[i][j])
				{
					value[m] = environ[i][j];
					j++;
					m++;
				}
				return (value);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

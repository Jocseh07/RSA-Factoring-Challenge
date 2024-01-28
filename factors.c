#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * main - get the factors
 * @ac: no of values
 * @av: array of values
 * Return: failure or 0 if successful
 */

int main(int ac, char **av)
{
	FILE *file;
	long int a = 0, b = 2, c = 0;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread = 0;

	if (ac != 2)
		exit(EXIT_FAILURE);
	file = fopen(av[1], "r");
	if (file == (NULL))
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, file)) != -1)
	{
		a = atoll(line);
		c = (a / 2) + 1;
		while (b < c)
		{
			if (a % b == 0)
			{
				printf("%ld=%ld*%ld\n", a, a / b, b);
				break;
			}
			b++;
		}
	}
	free(line);
	fclose(file);
	return (0);
}

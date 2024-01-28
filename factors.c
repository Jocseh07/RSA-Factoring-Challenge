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
	long int b = 0, c = 0;
	char *line = NULL;
	long int a[1000];
	long int i = 0;

	if (ac != 2)
		exit(EXIT_FAILURE);
	file = fopen(av[1], "r");
	if (file == (NULL))
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	while (fscanf(file, "%ld", &a[i]) != EOF)
	{
		c = (a[i] / 2) + 1;
		for (b = 2; b < c; b++)
		{
			if (a[i] % b == 0)
			{
				printf("%ld=%ld*%ld\n", a[i], a[i] / b, b);
				break;
			}
		}
		i++;
	}
	free(line);
	fclose(file);
	return (0);
}

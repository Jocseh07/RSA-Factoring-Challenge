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
	char *line = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	long long number = 0, div = 2, rem = 0, count = 0;

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
		number = atoll(line);
		div = 2;
		while (div < ((number / 2) + 1))
		{
			if (number % div == 0)
			{
				count = number / div;
				printf("%lld=%lld*%lld\n", number, count, div);
				break;
			}
			div++;
		}
	}
	free(line);
	fclose(file);
	exit(EXIT_SUCCESS);
}

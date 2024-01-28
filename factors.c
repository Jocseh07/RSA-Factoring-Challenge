#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

/**
 * main - get the factors
 * @ac: no of values
 * @av: array of values
 * Return: failure or 0 if successful
 */

__int128 atoll128(char *str)
{
	__int128 total = 0;
	while (*str)
	{
		total *= 10;
		total += *str - '0';
		str++;
	}
	return total;
}

void print128(__int128 x)
{
	if (x)
		print128(x / 10);
	else
		return;
	printf("%d", (int)(x % 10));
}

int factorize(char *buffer)
{
	__int128 num, i;

	num = atoll128(buffer);
	for (i = 2; i < (num / 2 + 1); i++)
	{
		if (num % i == 0)
		{
			print128(num);
			printf("=");
			print128(num / i);
			printf("*");
			print128(i);
			printf("\n");
			break;
		}
	}
	return (0);
}

int main(int ac, char **av)
{
	FILE *file;
	char *line = NULL, *token;
	size_t len = 0;
	ssize_t nread = 0;
	long long flag = 1, div, rest, number, counter;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s <file>", av[0]);
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == (NULL))
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, file)) != -1)
	{
		token = strtok(line, "\n");
		factorize(token);
	}

	free(line);
	fclose(file);
	exit(EXIT_SUCCESS);
}

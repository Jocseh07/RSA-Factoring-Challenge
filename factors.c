#include <stdio.h>
#include <stdlib.h>

/**
 * main - get the factors
 * @ac: no of values
 * @av: array of values
 */

int main(int ac, char **av) {
  FILE *file;
  int a = 0, b = 0, c = 0;
  char *line = NULL;
  size_t len = 0;
  ssize_t nread = 0;

  if (ac != 2)
    exit(EXIT_FAILURE);
  file = fopen(av[1], "r");
  if (file == (NULL)) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }
  while ((nread = getline(&line, &len, file)) != -1) {
    a = atoi(line);
    c = (a / 2) + 1;
    for (b = 2; b < c; b++) {
      if (a % b == 0) {
        printf("%d=%d*%d\n", a, a / b, b);
        break;
      }
    }
  }
  free(line);
  fclose(file);
  return (0);
}

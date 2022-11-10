#include <stdlib.h>
#include <stdio.h>

/**
* main - get line from stdin
*
* Return: always 0
*/
int main(__attribute__((unused))int ac, __attribute__((unused))char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t lineread;

	printf("$ ");
	lineread = getline(&line, &len, stdin);
	printf("%s\n", line);
	printf("No of character: %ld\n", lineread);

	free(line);
	exit(EXIT_SUCCESS);
}

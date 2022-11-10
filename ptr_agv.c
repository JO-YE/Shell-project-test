#include <stdio.h>
#include <stdlib.h>

/**
* main - prints all argument, followed by a new line
* @ac: argument count
* @av: array thst contains the program command line agrument
*
* Return: Always 0.
*/
int main(__attribute__((unused))int ac, char *av[])
{
	int index;

	for(index = 0; av[index]; index++)
	{
		printf("argv[%d]: %s\n", index, av[index]);
	}
	return (0);
}

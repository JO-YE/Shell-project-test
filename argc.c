#include <stdio.h>
#include <stdlib.h>

/**
* main - function that print argument
* @argc: agrument count
* @argv: agrument vector
*
* Return: always 0
*/
int main(int argc, char **argv)
{
	int index;

	for (index = 0; index < argc; index++)
		printf("arg[%d]: %s\n", index, argv[index]);
	exit (EXIT_SUCCESS);
}

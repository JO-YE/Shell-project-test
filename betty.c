#include <stdio.h>
#include <unistd.h>

/*
* main - prints its name followed by a new line
* @ac: argument count
* @av: argument vector
*
* Return: always 0
*/
int main(__attribute__((unused))int ac, __attribute__((unused)) char **av)
{
	char name[20];

	printf("Enter your name:\n");
	scanf("%s", name);
	printf("Welcome to your shell project %s", name);
	printf("\nLet's get started!\n");

	return (0);
}

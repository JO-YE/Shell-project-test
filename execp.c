#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
* main - a program that calls another program
*
* Return: always zero
*/
int main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
	char *arglist[3];
	arglist[0] = "/usr/bin/cat";
	arglist[1] = "split.c";
	arglist[2] = NULL;

	printf("execve about to run a program\n");
	if (execve(arglist[0], arglist, NULL) == -1)
	{
	perror("refuse to run ");
	}
	return (0);
}

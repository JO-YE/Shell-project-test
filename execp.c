#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
* main - a program that calls another program
* @argc: argument count
* @argv: argument vector
* Return: always zero
*/
int main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
	char *arglist[3];

	arglist[0] = "/usr/bin/vi";
	arglist[1] = "split.c";
	arglist[2] = NULL;

	printf("execve about to run a program\n");
	if (execve(arglist[0], arglist, NULL) == -1)
	{
	perror("refuse to run ");
	}
	return (0);
}

/** 
* Complied this program into 3 different result
* the first only listed the files
* the second one cat the split.c file
* the third vi split.c
* it can be ran using ./(complied name)
* Refer to EXECVE.C and EXECTEST.C  file for more example and information*/

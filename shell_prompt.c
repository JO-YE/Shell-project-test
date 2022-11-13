#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include <signal.h>
#include <unistd.h>

#define MAXARGS 20
#define ARGLEN 100

/**
* main - function that prompt the user for a pn and arg
*
* Return: always 0
*/
int main(void)
{
	char *arglist[MAXARGS + 1];
	char argbuf[ARGLEN];
	int numarg;
	char *makestring();

	numarg = 0;
	while (numarg < MAXARGS)
	{
		printf("Arg[%d]:  ", numarg);
		if (fgets(argbuf, ARGLEN, stdin) && *argbuf != '\n')
			arglist[numarg++] = makestring(argbuf);
		else
		{
			if (numarg > 0)
			{
				arglist[numarg] = NULL;
				execute(arglist);
				numarg = 0;
			}
		}
	}
	return (0);
}

/**
* execute - executing the program using execvp
* @arglist: argument list
*
* Return: always 0
*/
int execute(char *arglist[])
{
	execvp(arglist[0], arglist);
	perror("refuse to run ");
	exit(EXIT_SUCCESS);
}

/**
* makestring - a function that trim off new line and create
* storage for the string
* @buf: a temporary wtorage area
*
* Return: always 0
*/
char *makestring(char *buf)
{
	char *copy;
	copy = malloc(2); 
/** added a random number to the bracket to solve the malloc error**/
	buf[strlen(buf) - 1] = '\0';
	copy = malloc(strlen(buf) + 1);
	if (copy == NULL)
	{
		fprintf(stderr, "no memory\n");
		exit(EXIT_SUCCESS);
	}
	strcpy(copy, buf);
	return copy;
}

/** code worked. But still needs to look up on malloc issues**/
/** Complied this program to give 2 diff result **/
/** the first one will print arg(): while the second **/
/** print only $. both will need for the user to pree Ctrl d**/

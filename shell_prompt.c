#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include <signal.h>

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
		printf("Arg[%d]:", numarg);
		if (getline(argbuf, ARGLEN, stdin) && *argbuf != '\n')
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

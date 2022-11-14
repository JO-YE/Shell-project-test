#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAXARGS 20
#define ARGLEN 100

/**
* main - function that prompt the user
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
		printf("#cisHard&Fun$ ");
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
* execute - executing the program using fork, execve and wait
* @arglist: argument list
*
* Return: always 0
*/
int execute(char *arglist[])
{
	int childprocess, wait_rv;

	childprocess = fork();
	switch (childprocess)
	{
		case -1:
			perror("Problem with Fork");
			exit(EXIT_SUCCESS);
		case 0:
			execvp(arglist[0], arglist);
			perror("Issue with execve");
			exit(EXIT_SUCCESS);
		default:
			wait_rv = wait(NULL);
			while (wait_rv != childprocess)
				;
			printf("child exited\n");
	}
	return (0);
}

/**
* 
* makestring - a function that trim off new line and create
* storage for the string
* @buf: a temporary storage area
*
* Return: always 0
*/
char *makestring(char *buf)
{
	char *copy;
	copy = malloc(2);

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

/** this code worked but isnt giving the desired result 
* for example if i want to cat a file, 
* i will need to write cat and the filename on separate lines, 
* it ought to be one the same line.
* I need to work more on how to get input from Stdin snd puttig it into array
* To be able to use main(ac, av) strtok, getline to write a new shell
*/


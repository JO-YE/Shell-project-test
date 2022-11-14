#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
* main - function that runs another program
* @argc: argument count
* @argv: argument vector
*
* Return: always 0
*/
int main(int argc, char **argv)
{
	char *Arg[] = { NULL, "She", "is", "trying", "her", "best", NULL};
	char **evn = { NULL };

	if (argc != 2)
	{
		fprintf(stderr, "Arg count must be 2\n");
		exit(EXIT_FAILURE);
	}

	Arg[0] = argv[1];

	execve(argv[1], Arg, evn);
	perror("execve failed");
	exit(EXIT_SUCCESS);
}
/** this code more or less performs the same function as execp.c 
* But this code will be use to run other compiled codes
* Null must alway end the argument otherwise execve will give Bad address
 * The major different btw this code and the one is execp.c is;
 * This code has the ability to run other programs that are not in this current code
 * while execp.c only ran the particular instruction given in the code
 * check exectest.c file for more information */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
* main - a test function
* @argc: argument count
* @argv: argument vector
*
* Return: always 0
*/
int main(int argc, char **argv)
{
	char *Arglist[] = { NULL, "echo", "testing", NULL};
	char **Env = { NULL };

	if (argc > 2)
	{
		fprintf(stderr, "Agr count shouldnt be more than 2");
		exit(EXIT_FAILURE);
	}

	Arglist[0] = argv[1];

	execve(argv[1], Arglist, Env);
	perror("execve failed");
	exit(EXIT_SUCCESS);
}

/** This code alway work the same way has execve.c
* since the first parameter is argv[1], it will alway run whatever compiled file that fall to index(1). 
* Same thing also happened in execp.c file, ot only ran the what was in arglist[0] and then things in arglist */

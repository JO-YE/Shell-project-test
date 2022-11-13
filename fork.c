#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

/**
* main - function that create child process
*
* Return: always 0
*/
int main(void)
{
	int child, parent;

	parent = getpid();
	printf("Before birthing to child, my pid is : %d\n", parent);
	child = fork();
	if (child == -1)
	{
		perror("Error: ");
		return (1);
	}
	printf("After birthing child, my pid is %d\n my child returned %d\n", parent, child);

	return (0);
}

/** if i had used pid_t child and pid_t parent instead */
/* then i would have used %u if printf instead of %d */
/* check pid.c file */
/* The pid of the child process is returned to the parent */
/* and 0 is returned to the child */
/* fork makes a copy of a process */

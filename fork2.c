#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/**
* main - functions that create process from child  process
* 
* Return: always 0
*/
int main(void)
{
	printf("My pid is %d\n", getpid());
	printf("My ppid is %d\n", getppid());
	fork();
	fork();
	fork();
	printf("My pid is %d\n", getpid());
	printf("My ppid is %d\n", getppid());
	return (0);
}

/** getpid() prints the PID of the current process */
/* getppid() prints the Parent PID 'PPID' */
/* This program shows how child process picks up at return */

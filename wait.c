#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
* main - a function that wait for child process to finish
*
* Return: always 0
*/
int main(void)
{
	int child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror("Error: ");
		return (1);
	}
	if (child == 0)
	{
		printf("Hello! child %d is here. Am current running\n", getpid());
		sleep(2);
		printf("Am not done yet, Pls wait for me\n");
		sleep(4);
	}
/** sleep() causes the calling thread to sleep either until the
*  number of real-time seconds specified in seconds have elapsed 
* until a signal arrives which is not ignored. */
	else
	{
		wait(&status);
		printf("Finally! My child is done\n");
		sleep(2);
		printf("Alright, it all good now. My child returned %d\n", child);
/** this is just to emphasis that the pid of the child's process will alway be returned to the parent */
	}
	return (0);
}
/** A return 0 means that the program will execute successfully and did what it was intended to do. 
* A return 1 means that there is some error while executing the program, and it is not performing what it was intended to do. */

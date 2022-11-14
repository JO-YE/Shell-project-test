#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define DELAY 3
/**
* main - function that shows how parent pauses until child finishes
*
* Return: always 0
*/
int main(void)
{
	int newpid;
	void childfxn(), parentfxn();

	printf("Before fork(), my code is %d\n", getpid());

	newpid = fork();
	if (newpid == -1)
	{
		perror("Error: ");
		return (1);
	}
	else if (newpid == 0)
	{
		childfxn(DELAY);
	}
	else
	{
		parentfxn(newpid);
	}
/* since their return_type is void, they wont return anything.
* chidfxn and parentfxn are user defined functions that already been declared at the beginning of this code
* The next is to define each Function. that is, providing the fxn body*/
	return (0);
}

void childfxn(int delay)
/** 
* chidfxn - the new process takes a nap and exit
* @delay: number of seconds
*
* Return: returns void
*/
{
	printf("Hey! Child process(%d) is here, will sleep for %d seconds\n", getpid(), delay);
	sleep(delay);
	printf("I am done, about to exit\n");
	exit(EXIT_SUCCESS);
}

void parentfxn(int newpid)
/** 
* parentfxn - parent wait for child and then prints a message
* @newpid: the pid of the child process
*
* Return: returns void
*/
{
	int wait_rv;
/* return value of wait */

	wait_rv = wait(NULL);
	printf("Parent process resumed.\n Done waiting for %d. Wait returned: %d\n", newpid, wait_rv);
}

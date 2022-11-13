#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
* main - function that differciate parent from child
*
* Return: always 0
*/
int main(void)
{
	pid_t father;
	pid_t child;
/** am using pid_t in this program, so i would be using %u instead of %d */
/** check fork.c- i used int there */

	child = fork();
	if (child == -1)
	{
		perror("Error: ");
		return (1);
	}
	father = getpid();
	printf("My pid is %u\n", father);
	if (child == 0)
	{
		printf("I am the child! my pid is %u\n", father);
	}
	else
	{
		printf("I am the FATHER! my child is %u\n", child);
	}

	return (0);
}

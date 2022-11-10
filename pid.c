#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
* main - pid
* pid - ID of current process
*
* Return: Always 0
*/

int main(void)
{
	pid_t pid;

	pid = getpid();
	printf("%u\n", pid);
	return (0);
}

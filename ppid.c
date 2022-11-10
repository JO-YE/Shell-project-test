#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
* main - PID
* ppid - to get the ID of PP
*
* Return - Always 0
*/
int main(void)
{
	pid_t ppid;

	ppid = getppid();
	printf("%u\n", ppid);
	return (0);
}

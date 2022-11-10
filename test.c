#include <stdio.h>

/**
* test - second attempt
*
* Return: Alway 0
*/

int main(void)
{
	int cohort;

	printf("Enter cohort: ");
	scanf("\n%d", &cohort);
	if (cohort == 9)
	{
		printf("You are eligible for the shell project\n");
		printf("check your intranet for your project patner.\n");
	}
	else
	{
		printf("Oops!");
		printf("\nThis project is not for you\n");
	}

	return (0);
}

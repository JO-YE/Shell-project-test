#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* main - a function that split a string
*
* Returns: Always 0
*/
int main(void)
{
	char str[] = "Hello! I am learning about strtok but am hungry";
	char *token;
	/** note: the cont delimiter here is 'space' and
	  * it is on this basis that the string text would be separated */

	token = strtok(str, " ");
	printf("original string - %s\n", str);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	return (0);
}

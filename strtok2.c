#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
* main - example2 using two delimiter
*
* Return: always 0
*/
int main(void)
{
	char string[] = "My Favorite food are : Rice , Plantain , Amala and ewedu :"
		"and few others.";
	char *token;
	const char *c = "':'','";
/** I will be using delimiter : and , to separate the string **/

	token = strtok(string, c);

	while (token != NULL)
	{
		printf("'%s'\n", token);
		token = strtok(NULL, c);
	}

	return (0);
}

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
* main - a function that split string
*
* Return: always 0
*/
int main(void)
{
	char inputstr[100];
	char words[10][10];
	int wordindex = 0;
	int totalwords = 0;
	int indexctr = 0;

	printf("Enter a string: ");
	fgets(inputstr, sizeof(inputstr), stdin);
/* loop through each character in the string */
	for (indexctr = 0; (unsigned int)indexctr <= strlen(inputstr); indexctr++)
	{
/* if current character equals space or null */
		if (inputstr[indexctr] == ',' || inputstr[indexctr] == '\0')
		{
/* append the null character to the current word */
			words[totalwords][wordindex] = '\0';
			totalwords++;
/* reset the index to zero for the  next word */
			wordindex = 0;
		}
		else
/* found a character of a word */
		{
/* copy the character of a word */
			words[totalwords][wordindex] = inputstr[indexctr];
/* increment the index for the word */
			wordindex++;
		}
	}
	printf("\nWords from the string are : \n");
/* loop through all the words that were copied */
	for (indexctr = 0; indexctr < totalwords; indexctr++)
	{
/* print each word */
		printf("%s\n", words[indexctr]);
	}

	return (0);
}

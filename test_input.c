#include <stdio.h>
#include <stdbool.h> // For booleans in C
#include <stdlib.h>	 // For dynamic memory management i.e. dynamic arrays
#include "test_input.h"

/**
	Read string
 */

string read_string(const char* prompt)
{
	string input;
	printf("%s", prompt);
	scanf("%255[^\n]%*c", input.str); // scan input for 255 characters that are not new lines

	return input;
}

/**
	Read integer
 */

int read_integer(const char* prompt)
{
	string line;
	char temp;
	int input;

	line = read_string(prompt);

	/// 
	while(sscanf(line.str, "%i %c", &input, &temp) != 1)
	{
		printf("Please enter a whole number. \n");

		line = read_string(prompt);
	}

	return input;
}
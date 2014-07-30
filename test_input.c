#include <stdio.h>
#include <stdbool.h> // For booleans in C


#include "Definitions.h"

/**
	Read string
 */

string read_string(const char* prompt)
{
	string input;
	printf("%s", prompt);
	// The line below is attributable to Andrew Cain, Swinburne University of Technology
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

	
	while(sscanf(line.str, "%i %c", &input, &temp) != 1)
	{
		printf("Please enter a whole number. \n");

		line = read_string(prompt);
	}

	return input;
}


/**
	Read integer range
 */
int read_integer_range(const char* prompt, const int lower_int, const int upper_int)
{
	int input; 
	string error_message;

	input = read_integer(prompt);

	while(input < lower_int || input > upper_int)
	{
		/*
			Sprintf facilitates concatenation between strings and integers in C. This 
			function is used here to enter the lower and upper bounds of the range in 
			between which input is sought from the user
		*/
		sprintf(error_message.str, "Please enter a number between %i and %i", lower_int, upper_int);
		printf("%s\n", error_message.str);
		input = read_integer(prompt);
	}

	return input;
}

int read_integer_min_restricted(const char* prompt, const int lower_int)
{
	int input;
	string error_message;

	input = read_integer(prompt);

	while(input < lower_int)
	{
		sprintf(error_message.str, "Please enter a number greater than %i", lower_int - 1);
		printf("%s\n", error_message.str);
		input = read_integer(prompt);
	}

	return input;
}
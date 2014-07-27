/*
	System modules
*/
#include <stdio.h>
#include <stdbool.h> // For booleans in C

/*
	Modules program depends on
*/
#include "Test_Input.h"
#include "Debug.h"
/*
	First thing that prints when the program is loaded 
 */
void print_header()
{
	const char HASH[] = "#";
	const char AUTHOR_TITLE[] = "Author: ";
	const char AUTHOR_NAME[] = "Vignesh Sankaran";
	const char PROGRAM_NAME_TITLE[] = "Program name:";
	const char PROGRAM_NAME[] = "N-Queens";
	const char PROGRAM_DESCRIPTION_TITLE[] = "Description:";
	const char PROGRAM_DESCRIPTION[] = "Solves N-Queens problem based on user input";
	const char LICENSE_TITLE[] = "License:";
	const char LICENSE[] = "Apache 2.0";

	printf("\n%s %s \t\t %s \n", HASH, AUTHOR_TITLE, AUTHOR_NAME); // Prints out author details, start by printing a new line
	printf("%s %s \t %s \n", HASH, PROGRAM_NAME_TITLE, PROGRAM_NAME); // Prints out program name
	printf("%s %s \t\t %s \n", HASH, PROGRAM_DESCRIPTION_TITLE, PROGRAM_DESCRIPTION); // Prints out program description
	printf("%s %s \t\t %s \n \n", HASH, LICENSE_TITLE, LICENSE); // Prints out license for code in the program

}

/*
	Main menu for the program which displays all program modes
 */
void print_main_menu()
{
	const char SELECT[] = "Welcome! Please select an option below to continue.";
	const char OPTION_1[] = "[ 1 ] Solve for 1 n-queens problem";
	const char OPTION_2[] = "[ 2 ] Solve up to an n-queens problem";
	const char OPTION_3[] = "[ 3 ] Debug mode";
	const char OPTION_4[] = "[ 4 ] Quit";

	printf("%s \n", SELECT);
	printf("%s \n", OPTION_1);
	printf("%s \n", OPTION_2);
	printf("%s \n", OPTION_3);
	printf("%s \n", OPTION_4);
}

int get_user_input()
{
	const int MIN_NUM_RANGE = 1;
	const int MAX_NUM_RANGE = 4;
	const char PROMPT[] = "Selected option: ";

	int user_input;

	user_input = read_integer_range(PROMPT, MIN_NUM_RANGE, MAX_NUM_RANGE);

	return user_input;
}

void handle_user_input()
{
	const char EXIT_MESSAGE[] = "Now exiting the program. Goodbye. ";
	int user_input;

	user_input = get_user_input();

	switch(user_input)
	{
		case 1: 
			break;
		case 2:
			break;
		case 3:
			debug();
			break;
		case 4:
			printf("%s\n", EXIT_MESSAGE);
			break;
	}
}

/*
	Constructor function for the menu module
 */
void menu()
{
	print_header();
	print_main_menu();
	handle_user_input();

}
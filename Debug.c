/*
	System modules
*/
#include <stdio.h>
#include <stdbool.h> // For booleans in C
#include <stdlib.h>	 // For dynamic memory management i.e. dynamic arrays

/*
	External modules program uses
*/
#include "Array_Definition.h"
#include "Create_Array.h"
#include "Test_Input.h"


/**
	Returns a restricted integer value which will be the size of 
	the array. Set so that the array cannot be less than 1 in size. We wouldn't
	want a negative array now would we?
 */
int get_array_size()
{
	const char PROMPT[] = "Enter the size of the array: ";
	const int MIN_ARRAY_SIZE = 1;
	int array_size;

	array_size = read_integer_min_restricted(PROMPT, MIN_ARRAY_SIZE);

	return array_size;

}

/**
	
 */
void debug_menu()
{

}

/**
	Central function to debug module
 */
void debug()
{
	const int STARTING_3D_VALUE = 1; 
	const int STARTING_4D_VALUE = 1; 
	// For 3D and 4D arrays, more elements in the nth dimension will be added as solutions are generated

	// Ask user to enter size of array
	int array_size = get_array_size();

	// Create array to store solutions (3D array that stores solution, row and column)
	int ***n_queens_solutions = create_3D_array(array_size, array_size, STARTING_3D_VALUE);

	// Create array that stores all attempts to every solution
	int ****solution_attempts = create_4D_array(array_size, array_size, STARTING_3D_VALUE, STARTING_4D_VALUE);

	// Solve n queens problem
	
}
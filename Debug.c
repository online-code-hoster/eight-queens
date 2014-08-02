/*
	System modules
*/
#include <stdio.h>
#include <stdbool.h> // For booleans in C
#include <stdlib.h>	 // For dynamic memory management i.e. dynamic arrays

/*
	External modules program uses
*/
#include "Definitions.h"
#include "Create_Array.h"
#include "Print.h"
#include "Test_Input.h"
#include "Modify_Array.h"


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
/*
	Debug has been split into different functions because it was starting to get too damn big to manage properly
	I'm kind of surprised I didn't do this earlier if you ask me.
*/

/**
	Populates and initialises the values in the custom types storing the main solutions array and
	the array storing all attempts at a solution
 */
void populate_solution_variables(chessboard_array *n_queens_solutions, debug_chessboard_array *debug)
{
	const int STARTING_NO_CHESSBOARDS = 1;
	const int STARTING_NO_OF_SOLUTIONS = 0;
	const int STARTING_4D_VALUE = 1; // 4th dimension represents solutions found in debug array, so far this is for the first solution

	/*
		For main chessboard type storing solutions only
	*/

	// Find number of queens to solve for
	int n_queens = get_array_size();

	// Set maximum size of chessboard e.g. 8x8, 6x6 etc
	n_queens_solutions->max = n_queens;

	// Initialise array
	n_queens_solutions->solutions = create_3D_array(n_queens_solutions->max, n_queens_solutions->max, STARTING_NO_CHESSBOARDS);

	// Set number of solutions found to 0
	n_queens_solutions->no_of_solutions = STARTING_NO_OF_SOLUTIONS;

	/*
		For debug type storing every attempt to every solution
	*/

	// Set maximum size of chessboards allowable in debug array
	debug->max_chessboard_size = n_queens;

	// Initialise attempted solutions array values
	debug->solution_attempts = create_4D_array(debug->max_chessboard_size, debug->max_chessboard_size, STARTING_NO_CHESSBOARDS, STARTING_4D_VALUE);

	// Initialise number of attempts array values (FIX THIS UP ASAP, this could be much better structured)
	debug->no_of_attempts = create_1D_array(STARTING_NO_OF_SOLUTIONS + 1); // There are no solutions just yet, but I can't just insert 0 to create the array

	// Set found number of solutions to 0
	debug->no_of_solutions = STARTING_NO_OF_SOLUTIONS;

}

void print_arrays()
{
	// Print in debug mode

	// Print in non debug mode
}

void add_array_dimension()
{
	// 
}

void add_remove_queens()
{
	// Add a queen at position


	// Add another queen at position 


	// Remove the queen at position

	
}

/**
	Central function to debug module.
 */
void debug()
{
	const int STARTING_3D_VALUE = 1; 
	const int STARTING_4D_VALUE = 1; 
	// For 3D and 4D arrays, more elements in the nth dimension will be added as solutions are generated

	const int STARTING_NO_OF_SOLUTIONS = 0;
	const int TEST_NO_OF_ITERATIONS = STARTING_NO_OF_SOLUTIONS + 1;
	// 0 Can't be inserted into array printing functions since that won't print anything out for us debuggers to see :)

	const bool SOLUTION_ARRAY = true;

	const bool DEBUG = true;
	const bool NO_DEBUG = false;

	chessboard_array n_queens_solutions; // Declaring solution storing struct
	debug_chessboard_array debug; // Stores all attempts at all solutions

	// Populate the types variables created above with values
	populate_solution_variables(&n_queens_solutions, &debug);

	// Print debug and non debug versions of chessboard
	print_3D_array(n_queens_solutions.solutions, TEST_NO_OF_ITERATIONS, n_queens_solutions.max, SOLUTION_ARRAY, DEBUG);
	print_3D_array(n_queens_solutions.solutions, TEST_NO_OF_ITERATIONS, n_queens_solutions.max, SOLUTION_ARRAY, NO_DEBUG);

	printf("Array for chessboard has been created. \n");

	// Print debug array
	print_4D_array(debug.solution_attempts, TEST_NO_OF_ITERATIONS, TEST_NO_OF_ITERATIONS, n_queens, DEBUG);
	print_4D_array(debug.solution_attempts, TEST_NO_OF_ITERATIONS, TEST_NO_OF_ITERATIONS, n_queens, NO_DEBUG);

	printf("Array for storing all solution attempts has been created. \n");

	// FOR DEBUGGING PURPOSES ONLY: Testing of array modification functionality
	// Add dimension to the solutions and debug arrays

	const int NEW_ARRAY_SIZE = 2; 
	// Needs to be hard coded since no solutions have been found yet, and I don't want to hardcode that :P
	const bool NOT_CHESSBOARD = false;

	// Add a solution to the solutions array
	add_to_3D_array(n_queens_solutions.solutions, NEW_ARRAY_SIZE, n_queens);
	printf("Dimension added to n queens array\n");

	add_to_1D_array(debug.no_of_attempts, NEW_ARRAY_SIZE);
	printf("Dimensions added to number of attempts array in the debug variable\n");

	printf("Printing out the n_queens, debug and no_of_attempts arrays\n");
	print_3D_array(n_queens_solutions.solutions, NEW_ARRAY_SIZE, n_queens_solutions.max, SOLUTION_ARRAY, DEBUG);
	print_4D_array(debug.solution_attempts, NEW_ARRAY_SIZE, TEST_NO_OF_ITERATIONS, n_queens, DEBUG);
	print_1D_array(debug.no_of_attempts, NEW_ARRAY_SIZE, NOT_CHESSBOARD, NO_DEBUG);

	// Test adding and removing attacks based on inserted queen's position


	// Solve n queens problem


	// Print out solution generated by program, debug and non debug versions for both arrays

}
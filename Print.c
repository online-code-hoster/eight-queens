/*
	System modules
*/
#include <stdio.h>
#include <stdbool.h> // For booleans in C
#include <string.h> // For string modifications

/*
	User defined modules
*/
#include "Definitions.h"


/*
	Types aren't directly passed to each of the below functions so as to allow for
	the same function to accept both debug arrays and solutions arrays, which are of
	different natures. Both have 3D arrays in one way or another, but the 3rd dimension
	in both mean very different things, as illustrated below

	- 3rd dimension in debug arrays: a single solution, with 2D arrays for each attempt
	- 3rd dimension in solutions arrays: stores all solutions without any failed attempts
*/

/**
	Prints out chessboard in both the chessboard and debug arrays
 */
void print_2D_array(int** chessboard, int max_size, bool debug)
{
	
	const char QUEEN_CHAR[] = "Q";

	for (int i = 0; i < max_size; i++)
	{
		for (int j = 0; j < max_size; j++)
		{
			if (debug)
			{
				printf("%i  ", chessboard[i][j]); // Prints out number of attacks for each square
			}

			else
			{
				if (chessboard[i][j] == 0)
				{
					printf(" %s ", QUEEN_CHAR);
				}

				else
				{
					printf(" \u2593 "); //2593 is unicode for a chequered square, which appears on non queen squares
				}
			}
		}

		printf("\n"); // Print a new line at the end of a row
	}

	printf("\n");
}

/**
	Chessboard array gets passed to here. For loop which loops through all solutions
	is found here
 */
void print_3D_array(int*** array, int no_3D_iterations, int no_2D_iterations, bool solutions_array, bool debug)
{
	string heading; // Heading to print each time the chessboard is printed. Depends on array type inputted into function

	// Check if array being passed is for solutions array or debug array

	if (solutions_array)
	{
		strcpy(heading.str, "SOLUTION NO "); // Method of assigning strings to char arrays in structs
	}
	else
	{
		strcpy(heading.str, "ATTEMPT NO ");
	}

	for(int i = 0; i < no_3D_iterations; i++)
	{
		// Print required heading
		printf("%s%i: \n", heading.str, i + 1);
		print_2D_array(array[i], no_2D_iterations, debug);

		// Print new line after chessboard has been printed
		printf("\n");
	}

}

/**
	Used to print out the 4D debug array
 */
void print_4D_array(int**** array, int no_4D_iterations, int no_3D_iterations, int no_2D_iterations, bool debug)
{
	string heading;

	strcpy(heading.str, "SOLUTION NO ");

	for (int i = 0; i < no_4D_iterations; i++)
	{
		printf("%s%i", heading.str, i + 1);
		print_3D_array(array[i], no_3D_iterations, no_2D_iterations, false, debug);
	}
}
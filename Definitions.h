#ifndef DEFINITIONS
#define DEFINITIONS


// Equivalent of a string
typedef struct string
{
	char str[256];
} string;

// For storing solutions to n queens problem
typedef struct chessboard_array
{
	int*** solutions;
	int max; // maximum size of chessboard
	int no_of_solutions; // number of solutions found for n queens
} chessboard_array;

// Stores all attempts at 1 n queens solution 

// Type for storing all attempts made for each n queens solution
/*
	Perhaps a better way to do this is to have a custom type for each solution
	that stores a 3D array of each attempt and has a number of attempts stored there.

	The below method of having an array store the number of attempts instead of
	having an array of the above described custom type was done so as to avoid
	having to restructure the program to suit this rather weird "4D array" setup
	rather than having a proper 4D array. And also because it was going to have
	a rather weird for loop which I didn't want to go through ;)
*/
typedef struct debug_chessboard_array
{
	int**** solution_attempts; // 4D array which stores 
	int* no_of_attempts; // Corresponds to each 3D array position in the 4D array
	int no_of_solutions;
	int max_chessboard_size; // Set maximum size of chessboard

} debug_chessboard_array;

#endif
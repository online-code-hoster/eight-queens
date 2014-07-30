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

// Type for storing all attempts made for each n queens solution
// typedef struct debug_chessboard_array
// {
// 	int**** ;

// } chessboard_array;

#endif
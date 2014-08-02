#ifndef PRINT
#define PRINT

/**
	Print out 1D array, intended use to show number of attempts for each solution
 */
void print_1D_array(int* array, int max_size, bool chessboard, bool debug);

/**
	Print out 3D array, called directly to print out the solutions array
 */
void print_3D_array(int*** array, int no_3D_iterations, int no_2D_iterations, bool solutions_array, bool debug);

/**
	Print out a 4D array, called by the debug array which stores all attempts
	to solve every solution
 */
void print_4D_array(int**** array, int no_4D_iterations, int *no_3D_iterations, int no_2D_iterations, bool debug);

#endif
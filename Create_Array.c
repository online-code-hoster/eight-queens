/*
	System modules
*/
#include <stdio.h>
#include <stdlib.h>	 // For dynamic memory management i.e. dynamic arrays
#include <string.h>

/*
	Global constant for starting value for creating an integer array
*/

static const int STARTING_VALUE = 0;

/**
	The below are a daisy chain of functions, where the higher n-dimention
	array-creating functions are dependent on the lower n-dimention array 
	functions. Since I also couldn't figure out a way to have just one function
	that populated the array created, I put that inside the array creating
	functions instead. 
 */

/**
	Create a 1D array, and populate it
 */
int* create_1D_array(int max_rows)
{
	int *one_d_array = malloc(max_rows * sizeof(int *));
	
	for (int i = 0; i < max_rows; i++)
	{
		one_d_array[i] = STARTING_VALUE;
	}

	return one_d_array;
}

/**
	2D arrays contain columns and rows, with rows being 1D arrays
 */
int** create_2D_array(int max_rows, int max_cols)
{
	int **two_d_array = malloc(max_cols * sizeof(int *));

	for (int i = 0; i < max_cols; i++)
	{
		two_d_array[i] = create_1D_array(max_rows);
	}

	return two_d_array;
}

/**
	3D arrays can be visualised as a cube, with an n dimension storing
	multiple 2D arrays (or in our case, chessboards)
 */
int*** create_3D_array(int max_rows, int max_cols, int max_3D)
{	
	int ***three_d_array = malloc(max_3D * sizeof(int *));

	for (int i = 0; i < max_3D; i++)
	{
		three_d_array[i] = create_2D_array(max_rows, max_cols);
	}

	return three_d_array;
}

/**
	4D arrays are a little trickier. The best way to think of these is to
	think of an nth dimension storing multiple cubes. 

	For now, this is only used to store all possible attempts for a 
	given solution, where a 2D array stores a chessboard filled with 
	possible queen positions, the 3rd dimension storing the attempt no, 
	and the 4th dimension storing the solution for which that cube of 
	attempted solutions is for
 */
int**** create_4D_array(int max_rows, int max_cols, int max_3D, int max_4D)
{
	int ****four_d_array = malloc(max_4D * sizeof(int *));

	for (int i = 0; i < max_4D; i++)
	{
		four_d_array[i] = create_3D_array(max_rows, max_cols, max_3D);
	}

	return four_d_array;
}
/*
	System modules
*/
#include <stdio.h>
#include <stdbool.h> // For booleans in C
#include <stdlib.h>	 // For dynamic memory management i.e. dynamic arrays

/*
	External modules program uses
*/
#include "Create_Array.h"
#include "Definitions.h"

void add_to_1D_array(int *array, int new_array_size)
{
	const int INIT_VALUE = 0;
	// Add new space to 1D array
	array = (int *) realloc(array, new_array_size * sizeof(int *));

	// To initialise new spot in array, set value to 0 (stored as a constant)
	array[new_array_size - 1] = INIT_VALUE;
}

void add_to_2D_array(int **array, int new_array_size)
{
	array = (int **) realloc(array, new_array_size * sizeof(int **));

}

/**
	Add dimension to 3D array. Can either be 
 */
void add_to_3D_array(int ***array, int new_array_size, int chessboard_size)
{
	// Reallocate memory
	array = (int ***) realloc( array, new_array_size * sizeof(int ***));

	// Create new 2D array in the new 3rd dimension
	array[new_array_size - 1] = create_2D_array(chessboard_size, chessboard_size);

}

/**
	Add dimension to 4D array, in this program's case, the debug array
 */
void add_to_4D_array(int ****array, int new_array_size, int chessboard_size)
{
	/*
		Number of 3D arrays to create after expansion. We only want 1 more cube after
		this 4D array has been expanded to accommodate well, 1 more 3D array :P
	*/
	const int NEW_3D_ARRAYS = 1;

	// Reallocate memory
	array = (int ****) realloc(array, new_array_size * sizeof(int ****));

	// Create new 3D array
	array[new_array_size - 1] = create_3D_array(chessboard_size, chessboard_size, NEW_3D_ARRAYS);
}
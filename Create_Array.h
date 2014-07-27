#ifndef CREATE_ARRAY
#define CREATE_ARRAY

/**
	Populates and returns a 1D array
 */
int* create_1D_array(int max_rows);

/**
	Populates and returns a 2D array
 */
int** create_2D_array(int max_rows, int max_cols);

/**
	Populates and returns a 3D array
 */
int*** create_3D_array(int max_rows, int max_cols, int max_3D);

/**
	Populates and returns a 4D array
 */
int**** create_4D_array(int max_rows, int max_cols, int max_3D, int max_4D);

#endif
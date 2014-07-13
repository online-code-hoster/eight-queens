#include <stdio.h>
#include <stdbool.h> // For booleans in C
#include <stdlib.h>	 // For dynamic memory management i.e. dynamic arrays
#include "test_input.h"

// Struct for storing the array

typedef struct chessboard_array
{
	int** board;
	int max; // maximum size of array
} chessboard_array;

// Struct for passing current queen position and whether to increment or decrement
typedef struct queen_position
{
	int row_pos;
	int col_pos;
} queen_position;

/**
	Get input from user and return it
 */

int get_max()
{
	int max;
	const char prompt[] = "Enter size of chessboard: ";

	max = read_integer(prompt);

	return max;
}

/**
	Create and return a 2D array
 */
int** create_array(int max)
{
	int **array;

	// Allocate memory for pointers that will point to each row i.e. no of rows
	array = malloc(max * sizeof(int *));

	// Check to ensure memory is not null
	if (array == NULL)
	{
		printf("Out of memory\n");
		return NULL; // No exceptions in C, return null to pointer
	}

	// Allocate memory for each row in the array
	for (int i = 0; i < max; i++)
	{
		array[i] = malloc(max * sizeof(int *));

		// Check to ensure memory is not null
		if (array == NULL)
		{
			printf("Out of memory\n");
			return NULL;
		}
	}

	return array;
}

void populate_chessboard(chessboard_array* chessboard)
{
	for(int i = 0; i < chessboard->max; i++)
	{
		for (int j = 0; j < chessboard->max; j++)
		{
			chessboard->board[i][j] = 0;
		}
	}
}

void update_row(chessboard_array* chessboard, queen_position current_position, bool increment_up)
{
	int temp_col = 0; // Need variable to step through each column as that is where the variables are

	while (temp_col < chessboard->max)
	{
		if (temp_col != current_position.col_pos) // Ensure that the position the queen is at does not get updated
		{
			if (increment_up)
			{
				chessboard->board[current_position.row_pos][temp_col] = chessboard->board[current_position.row_pos][temp_col] + 1;
			}

			else
			{
				chessboard->board[current_position.row_pos][temp_col] = chessboard->board[current_position.row_pos][temp_col] - 1;
			}
			
		}

		temp_col++;
	}
}

void update_col(chessboard_array* chessboard, queen_position current_position, bool increment_up)
{
	int temp_row = 0;

	while (temp_row < chessboard->max)
	{
		if (temp_row != current_position.row_pos)
		{
			if (increment_up)
			{
				chessboard->board[temp_row][current_position.col_pos] = chessboard->board[temp_row][current_position.col_pos] + 1;
			}

			else
			{
				chessboard->board[temp_row][current_position.col_pos] = chessboard->board[temp_row][current_position.col_pos] - 1;
			}
		}

		temp_row++;
	}
}

void update_top_down_diagonal(chessboard_array* chessboard, queen_position current_position, bool increment_up)
{
	 int temp_row, temp_col;

	 if (current_position.row_pos <= current_position.col_pos)
	 {
	 	temp_row = 0;
	 	temp_col = current_position.col_pos - current_position.row_pos;

	 	while (temp_col < chessboard->max)
	 	{
	 		if (temp_row != current_position.row_pos && temp_col != current_position.col_pos)
	 		{
	 			if (increment_up)
	 			{
	 				chessboard->board[temp_row][temp_col] = chessboard->board[temp_row][temp_col] + 1;
	 			}

	 			else
	 			{
	 				chessboard->board[temp_row][temp_col] = chessboard->board[temp_row][temp_col] - 1;
	 			}
	 		}
	 		temp_row++;
	 		temp_col++;
	 	}
	 }

	 else
	 {
	 	temp_col = 0;
	 	temp_row = current_position.row_pos - current_position.col_pos;

	 	while (temp_row < chessboard->max)
	 	{
	 		if (temp_row != current_position.row_pos && temp_col != current_position.col_pos)
	 		{
	 			if (increment_up)
	 			{
	 				chessboard->board[temp_row][temp_col] = chessboard->board[temp_row][temp_col] + 1;
	 			}

	 			else
	 			{
	 				chessboard->board[temp_row][temp_col] = chessboard->board[temp_row][temp_col] - 1;
	 			}
	 		}
	 		temp_row++;
	 		temp_col++;
	 	}
	 }
}

void update_bottom_up_diagonal(chessboard_array* chessboard, queen_position current_position, bool increment_up)
{
	int temp_row, temp_col;

	if ((current_position.row_pos + current_position.col_pos) > chessboard->max - 1)
	{
		temp_row = chessboard->max - 1;
		temp_col = current_position.row_pos + current_position.col_pos - (chessboard->max - 1);
		// Since the row and column added together are too large for the array, the row will
		// be limited to the last possible row. To calculate the starting column position, 
		// the maximum size of the array (user inputted chessboard size - 1) from the queen's
		// current row and column. 

		while (temp_col < chessboard->max) // Since the starting column is the larger number, it is used as the condition in the while loop
	 	{
	 		if (temp_row != current_position.row_pos && temp_col != current_position.col_pos)
	 		{
	 			if (increment_up)
	 			{
	 				chessboard->board[temp_row][temp_col] = chessboard->board[temp_row][temp_col] + 1;
	 			}

	 			else
	 			{
	 				chessboard->board[temp_row][temp_col] = chessboard->board[temp_row][temp_col] - 1;
	 			}
	 		}
	 		temp_row--; // Go up the chessboard for each row, going down would be ++
	 		temp_col++;
	 	}
	}

	else
	{
		temp_row = current_position.row_pos + current_position.col_pos;
		temp_col = 0;

		while (temp_row >= 0) // Row is the largest number, and is decremented until it goes past 0
	 	{
	 		if (temp_row != current_position.row_pos && temp_col != current_position.col_pos)
	 		{
	 			if (increment_up)
	 			{
	 				chessboard->board[temp_row][temp_col] = chessboard->board[temp_row][temp_col] + 1;
	 			}

	 			else
	 			{
	 				chessboard->board[temp_row][temp_col] = chessboard->board[temp_row][temp_col] - 1;
	 			}
	 		}
	 		temp_row--;
	 		temp_col++;
	 	}

	}
}

/** 
	Update the array as each potential solution is tested
 */

void update_attacks(chessboard_array* chessboard, int cur_row, int cur_col, bool increment_up)
{
	queen_position current_position;

	// Bundle inserted row and column into one variable
	current_position.row_pos = cur_row;
	current_position.col_pos = cur_col;

	// Update row and column 
	update_row(chessboard, current_position, increment_up);
	update_col(chessboard, current_position, increment_up);

	// Update top left to bottom right diagonal
	update_top_down_diagonal(chessboard, current_position, increment_up);

	// Update bottom left to top right diagonal
	update_bottom_up_diagonal(chessboard, current_position, increment_up);

}

void print_chessboard(chessboard_array chessboard, bool debug)
{
	const char QUEEN_CHAR[] = "Q";

	for (int i = 0; i < chessboard.max; i++)
	{
		for (int j = 0; j < chessboard.max; j++)
		{
			if (debug)
			{
				printf("%i  ", chessboard.board[i][j]); // Prints out number of attacks for each square
			}

			else
			{
				if (chessboard.board[i][j] == 0)
				{
					printf(" %s ", QUEEN_CHAR);
				}

				else
				{
					printf(" \u2593 ");
				}
			}
		}

		printf("\n"); // Print a new line at the end of a row
	}

	printf("\n");
}

/**
	Main recursive function
 */
bool eight_queens(chessboard_array* chessboard, int col)
{
	// loop through all rows

	for (int i = 0; i < chessboard->max; i++)
	{
		if (col > (chessboard->max - 1))
		{
			return true;
		}

		else
		{
			if (chessboard->board[i][col] == 0)
			{
				// Update chessboard array to position queen at current position
				update_attacks(chessboard, i, col, true);
				// print_chessboard(*chessboard, true);

				if (eight_queens(chessboard, col + 1))
				{
					return true;
				}

				else
				{
					update_attacks(chessboard, i, col, false); // False is used to denote removing queen from chessboard
					// print_chessboard(*chessboard, true);
				}
			}
		}
	}

	return false;
}

/**
	Checks if there is a solution to the n-queen on chessboard problem
	based on what n value was specified by the user after recursive function
	has run
 */
void check_solution(chessboard_array* chessboard, bool solution)
{
	if (!solution) // If there is no solution to the n queens problem
	{
		printf("There is no solution to the %i queens problem\n", chessboard->max);
	}

	else
	{
		printf("Solution to %i queens problem: \n", chessboard->max);
		print_chessboard(*chessboard, false);
	}
}

/**
	Program initiated here
 */

int main(int argc, char const *argv[])
{
	chessboard_array chessboard;
	bool solution;

	chessboard.max = get_max();

	chessboard.board = create_array(chessboard.max);

	if (chessboard.board == NULL) // No exceptions in C, if no memory allocated to array, terminate the program
	{
		return 1;
	}

	populate_chessboard(&chessboard);

	solution = eight_queens(&chessboard, 0);

	check_solution(&chessboard, solution);

	// For debugging purposes to test the array functionality
	// const char ROW_PROMPT[] = "Enter row number: ";
	// const char COL_PROMPT[] = "Enter column number: ";
	// queen_position cur_pos;

	// cur_pos.row_pos = read_integer(ROW_PROMPT);
	// cur_pos.col_pos = read_integer(COL_PROMPT);

	// Add a queen to the chessboard
	// update_attacks(&chessboard, cur_pos.row_pos, cur_pos.col_pos, true);
	// print_chessboard(chessboard, true);
	//
	// Remove queen from the chessboard
	// update_attacks(&chessboard, cur_pos.row_pos, cur_pos.col_pos, false);
	// print_chessboard(chessboard, true);


	return 0;
}
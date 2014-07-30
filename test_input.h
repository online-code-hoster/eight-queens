#ifndef TEST_INPUT
#define TEST_INPUT

/**
	Read an integer
 */

int read_integer(const char* prompt);

/**
	Read an integer range set by the calling code
 */
int read_integer_range(const char* prompt, const int lower_int, const int upper_int);

/**
	Reads an integer with a set minimum value to be entered
 */

int read_integer_min_restricted(const char* prompt, const int lower_int);

#endif
#ifndef TERMINAL_USER_INPUT_H
#define TERMINAL_USER_INPUT_H

/**
	This struct is the equivalent of a string
 */

typedef struct string
{
	char str[256];
} string;

/**
	Read an integer
 */

int read_integer(const char* prompt);

#endif
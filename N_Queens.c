/*
	System modules
*/
#include <stdio.h>
#include <stdbool.h> // For booleans in C
#include <stdlib.h>	 // For dynamic memory management i.e. dynamic arrays

/*
	Modules program depends on
*/
#include "Menu.h" // Menu is called from here

int main(int argc, char const *argv[])
{
	menu();
	return 0;
}
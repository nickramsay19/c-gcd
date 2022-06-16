#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/GCD.h"

int main(int argc, char **argv) {

	int a, b;

	if (argc < 2) {
		printf("Must provide two integers, a and b\n");
		return 0;
	} else if (argc > 2) {
		// check if the name of the program counts as an arg, if so don't include it
		a = atoi(argv[1]);
	    b = atoi(argv[2]);
	} else {
		a = atoi(argv[0]);
		b = atoi(argv[1]);
	}
	
	GCD(a, b);

	return 0;
}

#include "include/GCD.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int num_cols(int n) {
	int m = 1;
	int p = 1;

	// find the greatest power of 10 that divides n
	while (n / m > 0) {
		m *= 10;

		// note the current power of 10
		p++;
	}
	
	return p;
}

int pad(char* buf, int n, int width) {

	// get the amount of digits/columns in n
	int cols = num_cols(n);	

	// get the number as a string
	char* num_str = (char*) calloc((cols+1), sizeof(char));
	sprintf(num_str, "%d", n);
	//printf("the converted string: %s\n", num_str);

	printf("%d, %d, %d\n", n, width, cols);

	if (cols > width) {
		printf("ERROR: n's colums exceed to given width\n");
		return EXIT_FAILURE;
	}

	// g
	//printf("about to test\n");
	//printf("%c\n", buf[0]);

	printf("About to strcpy\n");
	// fill the begginning of the buffer with the number as a string
	for (int i = 0; i < cols; i++) {
		buf[i] = num_str[i];
	}

//	printf("add padding\n");

	// add the padding at the end
	for (int i = cols; i < width; i++) {
		buf[i] = ' ';
	}

	// free memory
	free(num_str);

	return EXIT_SUCCESS;
}

int GCD(int A, int B) {

	// copy A and B
	int a = A, b = B;

	// store quotient and remainder, and keep track of last remainder before 0
	// let r default to the second divisor, b
	int q, r = b, last_r;

	// get the amount of padding we want to add when printing numbers
	// get the maximum length of the numbers a and b
	int pad = max(num_cols(a), num_cols(b)); 
	// add 1 space of padding
	pad += 1;
	
	while (r > 0) {

		// keep track of the previous remainder before we change it
		last_r = r;
	
		// calculate the quotient and remainder
		q = a / b;
		r = a % b;

		// print the current step's calculation
		printf("|%*d  = %*d * %-*d + %*d\n", pad, a, pad, b, pad, q, pad, r);

		// get the next line's values
		a = b;
		b = r;
	}

	printf("--> GCD(%d, %d) = %d\n", A, B, last_r);


	// print the last remainder before 0
	return last_r;
}

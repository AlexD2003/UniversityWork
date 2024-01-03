#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "complex_test.h"

int main(int argc, char** argv) {

	run_complex_tests(true);

	display_mandelbrot(100, 25, 100);
	getchar();

	
	return 0;
}
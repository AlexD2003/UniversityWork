#define _CRT_SECURE_DEBUG_NO_WARNINGS
#include <iostream>
using namespace std;


#include "complex_test.h"

int main(int argc, char** argv) {
#if ENABLE_TESTS > 0
	run_complex_tests(false);
#endif
	return 0;
}
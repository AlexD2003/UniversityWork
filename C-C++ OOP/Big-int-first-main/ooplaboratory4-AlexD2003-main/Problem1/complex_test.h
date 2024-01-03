#pragma once

#define ENABLE_TESTS 0

#if ENABLE_TESTS > 0
#include <string>
using namespace std;

#include "complex_number.h"

void run_complex_tests(bool verbose = true);
#endif



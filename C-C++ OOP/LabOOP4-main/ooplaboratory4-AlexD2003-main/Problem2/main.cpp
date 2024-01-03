#include "BigInteger.h"
#include "bigint_test.h"

#include <iomanip>
#include <iostream>
using namespace std;


long long int computeNthFibonacci(unsigned int n) {
    int a = 1;
    int b = 1; 
    int c = 1;
    if (n == 0)
        return c;
    n--;
    while (n != 0) {
        c = a + b;
        b = a;
        a = c;
        n--;
    }
    return b;
}


int main() {
#if ENABLE_TESTS > 0
	run_bigint_tests(true);
#endif

    long long int crt = -1;
    long long int prev = -1;
    bool isOverflow = false;
    for (int n = 0; n < 100; n+=10) {
        prev = crt;
        crt = computeNthFibonacci(n);
        if (crt < prev)
            isOverflow = true;
        cout << setw(5) << n << "\t" << setw(20)<<crt<<"\t"<<(isOverflow ? string(RED)+string("OVERFLOW !!!! ")+string(NC) : "") << endl;

    }
	return 0;
}
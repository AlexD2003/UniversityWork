#include "bigint_test.h"

#if ENABLE_TESTS > 0
#include <csetjmp>
#include <csignal>
#include <cstdbool>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

#include "BigInteger.h"


#define FIRST_TEST Sign_test
#define MAXSCORE 36
#define CHARITY 10


using namespace std;

static uint8_t testsPassed;
static volatile sig_atomic_t testStatus;
static uint8_t disable_exit_handler;
jmp_buf test_crash;

enum Test_e {
    Sign_test = 0,
    Comparison_test,
    NUM_TESTS,
};

string testName(int test) {
    if (test == Sign_test)
        return "Sign_test";
   
    if (test == Comparison_test)
        return "Comparison_test";
    
    if (test == NUM_TESTS)
        return "NUM_TESTS";

    return "";
}

uint8_t runTest(int test) {

    BigInteger A;
    BigInteger B;
    BigInteger C;
    BigInteger D;
    BigInteger E;


    switch (test) {
    case Sign_test: {
        if (A.sgn() != 0)
            return 1;
        B = BigInteger("278950284752");
        C = BigInteger("+7764853730760");
        D = BigInteger("-1930294385068");
        E = BigInteger("0000000000000000000");

        if (B.sgn() != 1)
            return 2;

        if (C.sgn() != 1)
            return 3;
        
        if (D.sgn() != -1)
            return 4;
        
        if (E.sgn() != 0)
            return 5;
        return 0;
    }

    case Comparison_test: {
        A = BigInteger("111122223333");
        B = BigInteger("911122223333");
        C = BigInteger("112122223333");
        D = BigInteger("110122223333");

        if (!(A <= B))
            return 1;

        if (A >= C)
            return 2;

        if (A <= D)
            return 3;

        if (!(A < C))
            return 4;

        if (!(A > D))
            return 5;



        A = BigInteger("88888888888888887777777777777777777777777777777777744444444444444444444111111111111111111");
        B = BigInteger("+88888888888888887777777777777777777777777777777777744444444444444444444111111111111111111");


        if (!(A == B))
            return 11;

        if ((A == C))
            return 2;

        return 0;
    }

    }
    
    return 255;
}

void segfault_handler(int signal) { // everyone knows what this is
    testStatus = 255;
    longjmp(test_crash, 1);
}

void exit_attempt_handler(void) { // only I decide when you are done
    if (disable_exit_handler)
        return; // allow this to be disabled
    testStatus = 255;
    longjmp(test_crash, 2);
}


void run_bigint_tests(bool verbose)
{

    testsPassed = 0;
    disable_exit_handler = 0;
    atexit(exit_attempt_handler);
    signal(SIGSEGV, segfault_handler);

    for (uint8_t i = FIRST_TEST; i < NUM_TESTS; i++) {
        
        uint8_t fail_type;
        try {

            testStatus = runTest(i);
            fail_type = setjmp(test_crash);
        }
        catch (...) {
            testStatus = 255;
            fail_type = 3;
        }
        if (verbose) { // it's verbose mode
            cout << "Test " + testName(i) + ": "
                << (testStatus == 0 ? GREEN "PASSED" NC : RED "FAILED" NC);
            if (testStatus == 255) {
                cout << ": due to a " RED
                    << (fail_type == 1
                        ? "segfault"
                        : (fail_type == 2
                            ? "program exit"
                            : (fail_type == 3 ? "exception being thrown"
                                : "program interruption")))
                    << NC << endl;
                cout << "\nWARNING: Program will now stop running tests\n" << endl;
                break;
            }
            else if (testStatus != 0) {
                cout << ": test " CYAN << testStatus << NC << endl;
            }
            else {
                cout << endl;
            }
        }
        if (testStatus == 0) {
            testsPassed++;
        }
    }

    disable_exit_handler = 1;

    uint8_t totalScore = (MAXSCORE - NUM_TESTS * 3) + testsPassed * 3;
    if (testsPassed == 0)
        totalScore = 0;

    if (verbose && testStatus != 255)
        cout << "\nYou passed " << unsigned(testsPassed) << " out of " << NUM_TESTS<< " tests" << endl;
    else if (testStatus == 255) {
        totalScore = CHARITY; // charity points
        if (verbose)
            cout << RED "Receiving charity points because your program crashes" NC<< endl<<endl;
    }
    
}
#endif
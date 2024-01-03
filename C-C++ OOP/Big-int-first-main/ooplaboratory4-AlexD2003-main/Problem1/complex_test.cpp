#include "complex_test.h"
#include <csetjmp>
#include <csignal>
#include <cstdbool>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <math.h>

#define RED "\033[0;31m"
#define CYAN "\033[0;36m"
#define GREEN "\033[0;32m"
#define NC "\033[0m"

#define FIRST_TEST Test_Create
#define MAXSCORE 20
#define CHARITY 0

#if ENABLE_TESTS > 0
bool cmpf(float A, float B, float epsilon = 0.005f)
{
	return (fabs(A - B) < epsilon);
}


static uint8_t testsPassed;
static volatile sig_atomic_t testStatus;
static uint8_t disable_exit_handler;
jmp_buf test_crash;


typedef enum {
	Test_Create,
	Test_Add,
	Test_Subtract,
	Test_ScalarMult,
	Test_Mult,
	Test_Conjugate,
	Test_Phase,
	Test_Magnitude,
	Test_Getters_Setters,
	Test_Equals,
	Test_Stream_Operators,
	Test_Display_Type,
	Num_Tests
}TestCases;


void segfault_handler(int signal) {
	testStatus = 255;
	longjmp(test_crash, 1);
}

void exit_attempt_handler(void) {
	if (disable_exit_handler)
		return; // allow this to be disabled
	testStatus = 255;
	longjmp(test_crash, 2);
}

void abrupt_termination_handler(int signal) {
	testStatus = 255;
	longjmp(test_crash, 3);
}

std::string testName(int test);
int run_test(int test);


std::string testName(int test) {
	if (test == Test_Create)
		return "Test_Create";
	if (test == Test_Add)
		return "Test_Add";
	if (test == Test_Subtract)
		return "Test_Subtract";
	if (test == Test_ScalarMult)
		return "Test_ScalarMult";
	if (test == Test_Mult)
		return "Test_Mult";
	if (test == Test_Phase)
		return "Test_Phase";
	if (test == Test_Magnitude)
		return "Test_Magnitude";
	if (test == Test_Conjugate)
		return "Test_Conjugate";
	if (test == Test_Getters_Setters)
		return "Test_Getters_Setters";
	if (test == Test_Equals)
		return "Test_Equals";
	if (test == Test_Stream_Operators)
		return "Test_Stream_Operators";
	if (test == Test_Display_Type) {
		return "Test_Display_Type";
	}
	return "";
}

int run_test(int test) {
	switch (test)
	{
	case Test_Create:
	{
		{
			Complex c = Complex(0, 0);
			if (c.getReal() != 0 || c.getImag() != 0)
				return 1;
		}

		{
			Complex c = Complex(100, 1000);
			if (c.getReal() != 100 || c.getImag() != 1000)
				return 2;
		}

		return 0;

	}

	case Test_Conjugate:
	{
		{
			Complex c = Complex(0, 0);
			Complex cc = c.conjugate();
			if (cc.getReal() != 0 || cc.getImag() != 0)
				return 1;
		}

		{
			Complex c = Complex(10, 10);
			Complex cc = c.conjugate();
			if (c.getReal() != cc.getReal() || c.getImag() != -cc.getImag())
				return 2;
		}

		return 0;
	}

	case Test_Add:
	{
		{
			Complex c1 = Complex(0, 0);
			Complex c2 = Complex(2, 2);
			Complex sum = c1.add(c2);
			if (sum.getReal() != c2.getReal() || sum.getImag() != c2.getImag())
				return 1;
		}

		{
			Complex c1 = Complex(0, 0);
			Complex c2 = Complex(2.0, 2.0);
			Complex sum = c1 + c2;
			if (sum.getReal() != c2.getReal() || sum.getImag() != c2.getImag())
				return 3;
		}


		{
			Complex c1 = Complex(100, -10);
			Complex c2 = Complex(-100, 10);
			Complex sum = c1.add(c2);
			if (sum.getReal() != 0 || sum.getImag() != 0)
				return 2;
		}

		{
			Complex c1 = Complex(100.5, -10);
			Complex c2 = Complex(-100, 10);
			Complex sum = c1 + c2;
			if (sum.getReal() != 0.5 || sum.getImag() != 0)
				return 4;
		}


		return 0;

	}

	case Test_Subtract: {
		{
			Complex c1 = Complex(0, 0);
			Complex c2 = Complex(2, 2);
			Complex diff = c1.subtract(c2);
			if (diff.getReal() != -c2.getReal() || diff.getImag()  != -c2.getImag())
				return 1;
		}

		{
			Complex c1 = Complex(100, -10);
			Complex c2 = Complex(-100, 10);
			Complex diff = c1.subtract(c2);
			if (diff.getReal() != 200 || diff.getImag() != -20)
				return 2;
		}

		{
			Complex c1 = Complex(100, -10);
			Complex c2 = Complex(-100, 10);
			Complex diff = c1 - c2;
			if (diff.getReal() != 200 || diff.getImag() != -20)
				return 4;
		}


		{
			Complex c1 = Complex(100, -10);
			Complex diff = c1.subtract(c1);
			if (diff.getReal() != 0 || diff.getImag() != 0)
				return 3;
		}


		{
			Complex c1 = Complex(100, -10);
			Complex diff = c1 - c1;
			if (diff.getReal() != 0 || diff.getImag() != 0)
				return 5;
		}

		{
			Complex c1 = Complex(0, 0);
			Complex c2 = Complex(2, 2);
			Complex diff = c1 - c2;
			if (diff.getReal() != -c2.getReal() || diff.getImag() != -c2.getImag())
				return 6;
		}

		return 0;
	}

	case Test_ScalarMult: {
		{
			Complex c1 = Complex(10, 0);
			c1.multiply(0);
			
			if (c1.getReal() != 0 || c1.getImag() != 0)
				return 1;
		}

		{
			Complex c1 = Complex(100, -10);
			c1.multiply(2);

			if (c1.getReal() != 200 || c1.getImag() != -20)
				return 2;
		}

		{
			Complex c1 = Complex(100, -10);
			c1.multiply(-2);

			if (c1.getReal() != -200 || c1.getImag() != 20)
				return 3;
		}
		return 0;
	}

	case Test_Mult: {
		{
			Complex c1 = Complex(10, 30);
			Complex c2 = Complex(30, 40);
			Complex sum = c1.multiply(c2);
			if (sum.getReal() != -900 || sum.getImag() != 1300)
				return 1;
		}

		{
			Complex c1 = Complex(0, 30);
			Complex c2 = Complex(300, 40);
			Complex sum = c1.multiply(c2);
			if (sum.getReal() != -1200 || sum.getImag() != 9000)
				return 2;
		}

		{
			Complex c1 = Complex(-100, 3);
			Complex c2 = Complex(7, -40);
			Complex sum = c1.multiply(c2);

			if (sum.getReal() != -580 || sum.getImag() != 4021)
				return 3;
		}

		{
			Complex c1 = Complex(-8, -3);
			Complex c2 = Complex(-7, -4);
			Complex sum = c1.multiply(c2);

			if (sum.getReal() != 44 || sum.getImag() != 53)
				return 4;
		}

		{
			Complex c1 = Complex(-8, -3);
			Complex c2 = Complex(0, 0);
			Complex sum = c1.multiply(c2);

			if (sum.getReal() != 0 || sum.getImag() != 0)
				return 5;
		}


		{
			Complex c1 = Complex(10, 30);
			Complex c2 = Complex(30, 40);
			Complex sum = c1 * c2;
			if (sum.getReal() != -900 || sum.getImag() != 1300)
				return 6;
		}

		{
			Complex c1 = Complex(0, 30);
			Complex c2 = Complex(300, 40);
			Complex sum = c1 * c2;
			if (sum.getReal() != -1200 || sum.getImag() != 9000)
				return 7;
		}

		{
			Complex c1 = Complex(-100, 3);
			Complex c2 = Complex(7, -40);
			Complex sum = c1 * c2;

			if (sum.getReal() != -580 || sum.getImag() != 4021)
				return 8;
		}

		{
			Complex c1 = Complex(-8, -3);
			Complex c2 = Complex(-7, -4);
			Complex sum = c1 * c2;

			if (sum.getReal() != 44 || sum.getImag() != 53)
				return 9;
		}

		{
			Complex c1 = Complex(-8, -3);
			Complex c2 = Complex(0, 0);
			Complex sum = c1 * c2;

			if (sum.getReal() != 0 || sum.getImag() != 0)
				return 10;
		}
		return 0;
	}

	case Test_Equals: {
		{
			Complex c1 = Complex(0, 100);
			Complex c2 = Complex(0, 100);


			if (!c1.equals(c2))
				return 1;
		}


		{
			Complex c1 = Complex(-10, 100);
			Complex c2 = Complex(100, -10);


			if (c1.equals(c2))
				return 2;
		}

		return 0;
	}

	case Test_Phase: {

		{
			Complex c = Complex(-10, -10);
			if (!cmpf(c.phase(), -2.35619f))
				return 1;
		}

		{
			Complex c = Complex(10, 100);
			if (!cmpf(c.phase(), 1.47113f))
				return 2;
		}

		{
			Complex c = Complex(-7, 7);
			if (!cmpf(c.phase(), 2.35619f))
				return 3;
		}

		{
			Complex c = Complex(1, -1);
			if (!cmpf(c.phase(), -0.785398f))
				return 4;
			float r;
			float theta;

			c.toPolar(&r, &theta);
			if (!cmpf(theta, -0.785398f))
				return 4;
		}

		{
			Complex c = Complex(0, 0);
			if (!cmpf(c.phase(), 0))
				return 5;

			float r;
			float theta;

			c.toPolar(&r, &theta);
			if (!cmpf(theta, 0))
				return 6;
		}

		return 0;
	}

	case Test_Getters_Setters: {
		Complex c = Complex(0, 0);
		c.setReal(4);
		if (!(c.getReal() == 4))
			return 1;
		c.setReal(-4);
		if (!(c.getReal() == -4))
			return 2;

		c.setImag(4);
		if (!(c.getImag() == 4 && c.getReal()== -4))
			return 3;

		c.setImag(-40);
		if (!(c.getImag() == -40 && c.getReal() == -4))
			return 4;
		return 0;
	}

	case Test_Display_Type: {
		Complex::setDisplayType(DisplayType::POLAR_FORM);
		{
			ostringstream sstr;
			Complex c;
			sstr << c;
			std::string expected{ "0" };
			if (c.toString() != expected) {
				cout << "Expected " << expected << ", but got " << c.toString() << endl;
				return 1;
			}
		}

		{
			ostringstream sstr;
			Complex c(sqrt(3), 1.0f);
			sstr << c;

			string expected{ "2.00*(cos(30.00) + i*sin(30.00))" };
			if (c.toString() != expected) {
				cout << "Expected " << expected << ", but got " << c.toString() << endl;
				return 2;
			}
		}

		{
			ostringstream sstr;
			Complex c{ 10, -20 };
			sstr << c;
			string expected{ "22.36*(cos(-63.43) + i*sin(-63.43))" };
			if (c.toString() != expected) {
				cout << "Expected " << expected << ", but got " << c.toString() << endl;
				return 3;
			}
		}

		{
			ostringstream sstr;
			Complex c{ 10, 0 };
			sstr << c;
			std::string expected = "10.00*(cos(0.00) + i*sin(0.00))";
			if (c.toString() != expected) {
				cout << "Expected " << expected << ", but got " << c.toString() << endl;
				return 4;
			}
		}


		return 0;
	}

	case Test_Stream_Operators: {
		Complex::setDisplayType(DisplayType::RECTANGULAR_FORM);
		{
			ostringstream sstr;
			Complex c;
			sstr << c;
			std::string expected{ "0" };
			if (c.toString() != expected) {
				cout << "Expected " << expected << ", but got " << c.toString() << endl;
				return 1;
			}
		}

		{
			ostringstream sstr;
			Complex c{10, 20};
			sstr << c;
			std::string expected = "10.00+20.00i";
			if (c.toString() != expected) {
				cout << "Expected " << expected << ", but got " << c.toString() << endl;
				return 2;
			}
		}

		{
			ostringstream sstr;
			Complex c{ 10, -20 };
			sstr << c;
			string expected{ "10.00-20.00i" };
			if (c.toString() != "10.00-20.00i") {
				cout << "Expected " << expected << ", but got " << c.toString() << endl;
				return 3;
			}
		}

		{
			ostringstream sstr;
			Complex c{ -10, -20 };
			sstr << c;
			std::string expected = "-10.00-20.00i";
			if (c.toString() != expected) {
				cout << "Expected " << expected << ", but got " << c.toString() << endl;
				return 4;
			}
		}

		{
			istringstream sstr("-10+20i");
			
			Complex c;
			sstr >> c;
			if (cmpf(c.getReal(), -10) == false || cmpf(c.getImag(), 20) == false)
				return 5;
		}

		{
			istringstream sstr("0");

			Complex c;
			sstr >> c;
			if (cmpf(c.getReal(), 0) == false || cmpf(c.getImag(), 0) == false)
				return 6;
		}

		{
			istringstream sstr("0.5");

			Complex c;
			sstr >> c;
			if (cmpf(c.getReal(), 0.5) == false || cmpf(c.getImag(), 0) == false)
				return 6;
		}

		{
			istringstream sstr("0.5+0.8i");

			Complex c;
			sstr >> c;
			if (cmpf(c.getReal(), 0.5f) == false || cmpf(c.getImag(), 0.8f) == false)
				return 7;
		}
		return 0;
	}
	case Test_Magnitude: {

		{
			Complex c = Complex(-10, -10);
			if (!cmpf(c.magnitude(), 14.1421f))
				return 1;
		}

		{
			Complex c = Complex(10, 100);
			if (!cmpf(c.magnitude(), 100.499f))
				return 2;
		}

		{
			Complex c = Complex(7, 7);
			float r;
			float theta;

			c.toPolar(&r, &theta);

			if (!cmpf(r, 9.8995f))
				return 3;

			if (!cmpf(c.magnitude(), 9.8995f))
				return 4;
		}


		{
			Complex c = Complex(0, 0);
			if (!cmpf(c.magnitude(), 0))
				return 5;
		}
		return 0;
	}

	default:
		break;
	}
	return 255;
}

void run_complex_tests(bool verbose) {
	testsPassed = 0;
	disable_exit_handler = 0;
	atexit(exit_attempt_handler);
	signal(SIGSEGV, segfault_handler);
	signal(SIGTERM, abrupt_termination_handler); // dangerous
	//signal(SIGINT, abrupt_termination_handler);
	//signal(SIGFPE, abrupt_termination_handler);
	//signal(SIGABRT, abrupt_termination_handler);
	for (uint8_t i = FIRST_TEST; i < Num_Tests; i++) {

		uint8_t fail_type;
		try {

			testStatus = run_test(i);
			fail_type = setjmp(test_crash);
		}
		catch (...) {
			testStatus = 255;
			fail_type = 3;
		}
		if (true) { // it's verbose mode
			cout << "Test " + testName(i) + ": "
				<< (testStatus == 0 ? GREEN "PASSED" NC : RED "FAILED" NC);
			if (testStatus == 255) {
				cout << ": due to a " RED << (fail_type == 1 ? "segfault" : (fail_type == 2 ? "program exit" : (fail_type == 3 ? "exception being thrown" : "program interruption"))) << NC << endl;
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

	short totalScore = testsPassed ;
	short maxScore = Num_Tests ;
	if (verbose) {
		if (testStatus != 255)
			cout << "\nYou passed " << unsigned(testsPassed) << " out of " << Num_Tests << " tests" << endl<<endl;
		else if (testStatus == 255) {
			totalScore = CHARITY;
			cout << RED "Receiving charity points because your program crashes" NC << endl;
		}
	}
	else {
		if (testStatus == 255)
			totalScore = CHARITY;
		cout << "Grade: "<<totalScore / (float)maxScore * 10 << endl;
	}
}
#endif
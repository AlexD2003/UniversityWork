#include <iostream>
#include <crtdbg.h>
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
using namespace std;
void exercise1() {
	// TODO your code here
	Circle c1{ 10, 10, 1 };
	Shape* c2{ new Circle{0, 0, 100 } };
	Circle c3{ -10, 0, 2 };

	Shape *s1{ new Square{ 0, 0, 2 }};
	Square s2{ 10, 20, 17 };
	Square s3{ 9, 100, 0.3 };
	
	// 1. create a polymorphic static array shapes with 6 elements that holds c1, c2, c3 and s1, s2 and s3
	Shape* shapes[6];
	shapes[0] = &c1;
	shapes[1] = c2;
	shapes[2] = &c3;
	shapes[3] = s1;
	shapes[4] = &s2;
	shapes[5] = &s3;
	// 2. display all the elements that have an area greater than 10
	for (int i = 0; i <= 5; i++) {
		if (shapes[i]->area() >= 10)
			cout << i<<" "<<shapes[i]->toString() << endl;
	}
		
	// 3. display all the circles from the array shapes
	for (int i = 0; i < 6; i++) {
		if (dynamic_cast<Circle*>(shapes[i])) {
			Circle* c = dynamic_cast<Circle*>(shapes[i]);
			cout << "Circle " << i << endl;;
		}
	}
		
	delete s1;
	delete c2;
}
int main() {
	exercise1();
	_CrtDumpMemoryLeaks();
	return 0;
}


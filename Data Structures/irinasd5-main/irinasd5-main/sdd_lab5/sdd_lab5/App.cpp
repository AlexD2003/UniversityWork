#include <iostream>

#include "ShortTest.h"
#include "ExtendedTest.h"

//sorted indexed list using binary search tree with linked representation on array. Every node of the tree will retain the number of ellements to the left of the node as well

int main(){
    testAll();
    testAllExtended();
    std::cout<<"Finished IL Tests!"<<std::endl;
	system("pause");
}
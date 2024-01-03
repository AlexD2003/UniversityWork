#include "Fox.h"
#include <iostream>
using namespace std;
Fox::Fox(int age) : fox_age(age) {}

EntityType Fox::getType() const {
    return EntityType::FOX;
}

void Fox::print() const {
    cout << "F" << fox_age;
}

Entity* Fox::next() {
    return this;
}

void Fox::move() {}
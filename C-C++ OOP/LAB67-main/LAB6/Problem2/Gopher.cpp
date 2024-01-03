#include "Gopher.h"
#include <iostream>
using namespace std;
Gopher::Gopher(int age) : gopher_age(age) {}

EntityType Gopher::getType() const {
    return EntityType::GOPHER;
}

void Gopher::print() const {
    cout << "G" << gopher_age;
}

Entity* Gopher::next() {
    return this;
}

void Gopher::move() {
}
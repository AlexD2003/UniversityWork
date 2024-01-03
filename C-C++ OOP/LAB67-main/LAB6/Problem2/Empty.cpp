#include "Empty.h"
#include <iostream>
using namespace std;
EntityType Empty::getType() const {
    return EntityType::EMPTY;
}

void Empty::print() const {
    cout << "E";
}

Entity* Empty::next() {
    return this;
}
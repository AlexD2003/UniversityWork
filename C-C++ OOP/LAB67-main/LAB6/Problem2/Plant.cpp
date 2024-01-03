#include "Plant.h"
#include <iostream>
using namespace std;
EntityType Plant::getType() const {
    return EntityType::PLANT;
}

void Plant::print() const {
    cout << "P";
}

Entity* Plant::next() {
    return this;
}
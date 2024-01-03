// Problem2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Entity.h"
#include "Plant.h"
#include "Animal.h"
#include "Fox.h"
#include "Gopher.h"
#include "Empty.h"
using namespace std;


int main() {
    vector<Entity*> entities;
    entities.push_back(new Plant());
    entities.push_back(new Empty());
    entities.push_back(new Fox(5));
    entities.push_back(new Gopher(7));

    for (Entity* entity : entities) {
        if ((entity->getType()) == EntityType::PLANT) {
            cout << "Plant:";
            entity->print();
        }
        if ((entity->getType()) == EntityType::GOPHER) {
            cout << "Gopher:";
            entity->print();
        }
        if ((entity->getType()) == EntityType::FOX) {
            cout << "Fox:";
            entity->print();
        }
        if ((entity->getType()) == EntityType::EMPTY) {
            cout << "Empty:";
            entity->print();
        }
        cout << endl;
    }

 

    return 0;
}
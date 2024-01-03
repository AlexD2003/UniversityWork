#ifndef GOPHER_H
#define GOPHER_H

#include "Animal.h"

class Gopher : public Animal {
public:
    Gopher(int age);
    EntityType getType() const override;
    void print() const override;
    Entity* next() override;
    void move() override;
private:
    int gopher_age;
};

#endif
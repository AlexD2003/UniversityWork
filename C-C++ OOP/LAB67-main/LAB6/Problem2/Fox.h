#ifndef FOX_H
#define FOX_H

#include "Animal.h"

class Fox : public Animal {
public:
    Fox(int age);
    EntityType getType() const override;
    void print() const override;
    Entity* next() override;
    void move() override;
private:
    int fox_age;
};

#endif 

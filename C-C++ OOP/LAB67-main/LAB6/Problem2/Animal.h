#ifndef ANIMAL_H
#define ANIMAL_H

#include "Entity.h"

class Animal : public Entity {
public:
    virtual void move() = 0;
};

#endif 
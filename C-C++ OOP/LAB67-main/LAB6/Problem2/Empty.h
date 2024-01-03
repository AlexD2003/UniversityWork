#ifndef EMPTY_H
#define EMPTY_H

#include "Entity.h"

class Empty : public Entity {
public:
    EntityType getType() const override;
    void print() const override;
    Entity* next() override;
};

#endif 
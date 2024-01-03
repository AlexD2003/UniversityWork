#ifndef PLANT_H
#define PLANT_H

#include "Entity.h"

class Plant : public Entity {
public:
    EntityType getType() const override;
    void print() const override;
    Entity* next() override;
};

#endif 
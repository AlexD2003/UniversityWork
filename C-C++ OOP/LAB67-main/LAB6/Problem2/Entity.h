#pragma once
#include "EntityType.h"
#include "SimulationGrid.h"

class Entity
{
public:
	// TODO make pure abstract method
	virtual EntityType getType() const = 0;
	virtual void print() const = 0;
	virtual Entity* next() = 0;
	virtual ~Entity() {}

	EntityType what() {
		return EntityType::EMPTY;
	}
protected:
	 int row;
	 int col;

	void demographics(unsigned int population[], const SimulationGrid& g);
private:
};


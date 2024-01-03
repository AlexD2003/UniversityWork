#pragma once
#include "EntityType.h"
#include "SimulationGrid.h"
#include <string>
using namespace std;
#define MAX_ROWS 100
#define MAX_COLS 100
class Entity
{
public:
	// TODO make pure abstract method
	Entity(int row, int col) : row(row), col(col) {}
	virtual ~Entity() {}
	virtual std::string toString();
	virtual EntityType what() {
		return EntityType::EMPTY;
	}
	virtual Entity* next(const Entity* const (&grid)[MAX_ROWS][MAX_COLS]) = 0;
protected:
	 int row;
	 int col;

	void demographics(unsigned int population[], const SimulationGrid& g);
private:
};

class Plant : public Entity {
public:
	Plant(int r, int c) : Entity(r, c) {}
	EntityType what() override { return EntityType::PLANT; }
	std::string toString() override { return "P"; }
	Entity* next(const Entity* const (&grid)[MAX_ROWS][MAX_COLS]) override;

};
class Empty : public Entity {
public:
	Empty(int r, int c) : Entity(r, c) {}
	EntityType what() override { return EntityType::EMPTY; }
	std::string toString() override { return "E"; }
	Entity* next(const Entity* const (&grid)[MAX_ROWS][MAX_COLS]) override;
};
class Fox : public Entity {
private:
	int age;

public:
	Fox(int r, int c) : Entity(r, c) {}
	EntityType what() override { return EntityType::FOX; }
	std::string toString() override { return "F"; }
	Entity* next(const Entity* const (&grid)[MAX_ROWS][MAX_COLS]) override;
};
class Gopher : public Entity {
private:
	int age;

public:
	Gopher(int r, int c) : Entity(r, c) {}
	EntityType what() override { return EntityType::GOPHER; }
	std::string toString() override { return "G"; }
	Entity* next(const Entity* const (&grid)[MAX_ROWS][MAX_COLS]) override;
};
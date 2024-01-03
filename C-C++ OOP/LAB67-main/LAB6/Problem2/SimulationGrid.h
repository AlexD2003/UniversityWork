#pragma once
#define MAX_ROWS 100
#define MAX_COLS 100
// forward class declaration for Entity
class Entity;
class SimulationGrid
{
	friend class Entity;

private:
	int rows;
	int cols;
	Entity* grid[MAX_ROWS][MAX_COLS];
};

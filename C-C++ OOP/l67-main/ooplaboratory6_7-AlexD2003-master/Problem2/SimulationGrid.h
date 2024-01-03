#pragma once
#include <iostream>
#include "Entity.h"
#define MAX_ROWS 100
#define MAX_COLS 100
using namespace std;
// forward class declaration for Entity

class SimulationGrid
{
	friend class Entity;
private:
    Entity* grid[MAX_ROWS][MAX_COLS];
public:
    SimulationGrid() {
        for (int r = 0; r < MAX_ROWS; r++) {
            for (int c = 0; c < MAX_COLS; c++) {
                grid[r][c] = new Empty(r, c);
            }
        }
    }
    ~SimulationGrid() {
        for (int r = 0; r < MAX_ROWS; r++) {
            for (int c = 0; c < MAX_COLS; c++) {
                delete grid[r][c];
            }
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const SimulationGrid& sg) {
        for (int r = 0; r < MAX_ROWS; r++) {
            for (int c = 0; c < MAX_COLS; c++) {
                os << sg.grid[r][c]->toString() << " ";
            }
            os << std::endl;
        }
        return os;
    }
    
};

    
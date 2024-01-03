#include "Entity.h"
#include "EntityType.h"
#include <algorithm> // for std::fill
#define MAX_ROWS 100
#define MAX_COLS 100
void Entity::demographics(unsigned int population[], const SimulationGrid& g) {
    std::fill(population, population + 4, 0);
    int dx[]{ 0, 0, 1, 1, 1, -1, -1, -1 };
    int dy[]{ 1, -1, -1, 0, 1,  -1, 0, 1 };
    unsigned int numNeigh{ sizeof(dy) / sizeof(dy[0]) };
    for (unsigned int i = 0; i < numNeigh; ++i) {
        int r{ row + dy[i] };
        int c{ col + dx[i] };
        if (r >= 0 && r < MAX_ROWS && c >= 0 && c < MAX_COLS) {
            EntityType et = g.grid[r][c]->what();
            population[static_cast<int>(et)]++;
        }
    }
}
Entity* Fox::next(const Entity* const (&grid)[MAX_ROWS][MAX_COLS]) {
    unsigned int population[4];
    Entity::demographics(population, grid);
    if (age >= 5) {
        return new Empty(row, col);
    }
    else if (population[static_cast<int>(EntityType::GOPHER)] == 0) {
        return new Empty(row, col);
    }
    else if (population[static_cast<int>(EntityType::FOX)] >= population[static_cast<int>(EntityType::GOPHER)]) {
        return new Fox(row, col);
    }
    else {
        return new Empty(row, col);
    }
}
Entity* Gopher::next(const Entity* const (&grid)[MAX_ROWS][MAX_COLS]) {
    unsigned int population[4];
    Entity::demographics(population, grid);
    if (age == 4) {
        return new Empty(row, col);
    }
    else if (population[static_cast<int>(EntityType::PLANT)] == 0) {
        return new Empty(row, col);
    }
    else if (population[static_cast<int>(EntityType::FOX)] >= population[static_cast<int>(EntityType::GOPHER)]) {
        return new Fox(row, col);
    }
    else {
        return new Gopher(row, col);
    }
}